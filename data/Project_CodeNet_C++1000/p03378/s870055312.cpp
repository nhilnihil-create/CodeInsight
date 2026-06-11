#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int a[101];

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    rep(i, m) {
        int b;
        cin >> b;
        a[b]++;
    }
    int l = 0;
    int r = 0;
    rep(i, x) {
        l += a[i];
    }
    repl(i, x, n) {
        r += a[i];
    }
    cout << min(l, r) << endl;
    return 0;
}