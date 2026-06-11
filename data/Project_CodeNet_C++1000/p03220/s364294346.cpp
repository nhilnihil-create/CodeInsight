#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    int t, a;
    cin >> t >> a;
    vector<int> H(n);
    rep(i, n) cin >> H[i];
    vector<P> h(n);
    rep(i, n) {
        h[i].second = i + 1;
        h[i].first = abs(1000 * t - H[i] * 6 - 1000 * a);
    }
    sort(h.begin(), h.end());
    cout << h[0].second << endl;
    return 0;
}