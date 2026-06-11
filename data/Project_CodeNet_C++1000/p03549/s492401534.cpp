#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    int x = 1900 * m + (n - m) * 100;
    int p = 1;
    rep(i, m) {
        p *= 2;
    }
    cout << p * x << endl;
    return 0;
}
