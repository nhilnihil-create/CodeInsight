#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define endl '\n'
#define el cout << endl
#define long long long
#define oo 1000000

const int N = 1e6;
int n;

int main()
{
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int r, d, x;
    cin >> r >> d >> x;
    rep(i, 10)
    {
        x = x*r - d;
        cout << x << endl;
    }
}
