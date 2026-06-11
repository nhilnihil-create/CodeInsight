// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
// #include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
// using namespace atcoder;
using ll = long long;
const int mod = 1e9 + 7;

int f(int b)
{
    int ret = 0;
    while (b)
    {
        ret += b % 10;
        b /= 10;
    }
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    int ans = 1e9;
    for (int a = 1; a < n; a++)
    {
        int b = n - a;
        ans = min(ans, f(b) + f(a));
    }
    cout << ans << endl;
}

int main()
{
    // srand((unsigned)time(NULL));
    // int t = clock();
    solve();
    // double et = 1.0 * (clock() - t) / CLOCKS_PER_SEC;
    // printf("Execution Time: %.4lf sec\n", et);
    return 0;
}