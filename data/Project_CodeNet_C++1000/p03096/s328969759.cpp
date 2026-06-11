#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int N; cin >> N;
    vector<int> cs(N + 1);
    cs[0] = -1;
    for (int i = 1; i <= N; ++i)
    {
        cin >> cs[i];
    }
    // dp[i]:i番目の石まで考えたときの塗り分け方の総和
    vector<LLONG> dp(N + 1, 0);
    // 各色に対するdp[j](j<i)の総和
    map<int, LLONG> color2dpSumMap;
    for (const int ci : cs)
    {
        color2dpSumMap[ci] = 0;
    }
    dp[0] = 1;
    for (int i = 1; i <= N; ++i)
    {
        // i番目を右端とする塗り替えができる場合
        // これまでの塗り分け方に(i-1)番目までの塗り方の総和を足したものが総塗り分け方
        if (cs[i - 1] != cs[i])
        {
            dp[i] = color2dpSumMap[cs[i]] + dp[i - 1];
            color2dpSumMap[cs[i]] += dp[i - 1];
        }
        // 前の石と色が同じ場合は，どちらを右端にしても変わらないので塗り分け方も引き継ぎ
        else
        {
            dp[i] = color2dpSumMap[cs[i]];
        }
        dp[i] %= MOD;
        color2dpSumMap[cs[i]] %= MOD;
        //// i番目を右端とした塗り替えを考える
        //// j番目までを飛ばし，j番目より後を塗り替えられるとき，
        //// （それ以前（j番目まで）の塗り方）×（j番目より後～i番目までの塗り方：１通り）だけ
        //// dp[i]を増やす
        //// ->単純に実装するとO(N^2)で間に合わない！
        //for (int j = 0; j < i; ++j)
        //{
        //    if (cs[j] != cs[i] && cs[j + 1] == cs[i])
        //    {
        //        dp[i] += dp[j];
        //    }
        //}
    }
    cout << color2dpSumMap[cs.back()] << endl;
}
