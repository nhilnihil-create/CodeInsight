// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using ll = long long;
using P = pair<int, int>;

// --------------------------------------------------------------------------------

void solve()
{
    int d, n;
    cin >> d >> n;
    int div = -1;
    if (d == 0)
        div = 1;
    else if (d == 1)
        div = 100;
    else if (d == 2)
        div = 10000;
    int cnt = 0;
    for (int i = div;; i += div)
    {
        if (i == 100 * div)
            continue;
        if (i % div == 0)
            cnt++;
        if (cnt >= n)
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