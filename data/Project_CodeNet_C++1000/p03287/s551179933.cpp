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
    int N, M; cin >> N >> M;
    vector<int> As(N); for (auto &Ai : As) cin >> Ai;
    // 累積和のmodを計算し，各余り値の数を数えておく：O(N~10^5)
    map<int, LLONG> mod2NumMap;
    int mod = As[0] % M;
    ++mod2NumMap[mod];
    for (int i = 1; i < N; ++i)
    {
        mod = (mod + As[i]) % M;
        ++mod2NumMap[mod];
    }
    LLONG ans = 0LL;
    // 余りがゼロのものはその箱単体を選べばよい
    auto zeroItr = mod2NumMap.find(0);
    if (zeroItr != mod2NumMap.end())
    {
        ans += zeroItr->second;
    }
    // 余りが非ゼロのもののうち，同じ余りをもつ箱の数nに対し
    // nC2通りの各ペアについて総和がMの倍数になる：O(N~10^5)
    for (const auto &kvp : mod2NumMap)
    {
        LLONG num = kvp.second;
        LLONG pairNum = num * (num - 1) / 2LL;
        ans += pairNum;
    }
    cout << ans << endl;
}

