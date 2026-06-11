#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 998244353;

const int Cin()
{
    int n;
    cin >> n;
    return n;
}

int main()
{
    int N = Cin();
    vector<int> As(N), Xs(N, 0);
    for (auto &Ai : As) Ai = Cin();
    // A_0 != 0 や A_i - A_{i-1} > 1 は実現できない
    int Aprev = -1;
    for (const int &Ai : As)
    {
        if (Ai - Aprev > 1)
        {
            cout << -1 << endl;
            return 0;
        }
        Aprev = Ai;
    }
    LLONG ans = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        // A_i + 1 = A_{i+1} のときは，X_i = Ai としてから１回操作を行えばよい
        if (As[i] + 1 == As[i + 1])
        {
            ++ans;
        }
        // そうでない場合（A_i >= A_{i+1} のとき）は，
        // まず X_{i+1} を A_{i+1} にするために As_{i+1} 回の操作が必要
        else
        {
            ans += As[i + 1];
        }
    }
    cout << ans << endl;
}