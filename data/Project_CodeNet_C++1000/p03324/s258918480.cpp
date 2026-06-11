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
    if (x % 100 != 0)
        return 0;
    return f(x / 100) + 1;
}

void solve()
{
    int d, n;
    cin >> d >> n;
    int cnt = 0;
    for (int i = 1;; i++)
    {
        if (d == f(i))
            cnt++;
        if (cnt == n)
        {
            cout << i << endl;
            return;
        }
    }
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