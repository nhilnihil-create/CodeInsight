// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using ll = long long;
using P = pair<int, int>;

// --------------------------------------------------------------------------------

int f(int x)
{
    if (x == 0)
        return 1;
    return f(x - 1) * 2;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = f(m) * (1800 * m + 100 * n);
    cout << ans << endl;
}

// --------------------------------------------------------------------------------

int main()
{
    // srand((unsigned)time(NULL));
    // int bt = clock();
    solve();
    // double et = 1.0 * (clock() - bt) / CLOCKS_PER_SEC;
    // printf("Execution Time: %.4lf sec\n", et);
    return 0;
}