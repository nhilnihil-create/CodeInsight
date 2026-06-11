#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    string s;
    cin >> s;

    vector<int> w(N + 1, 0);
    vector<int> b(N + 1, 0);
    rep(i, N) {
        if (s[i] == '#')
            b[i + 1] = 1;
    }
    reverse(all(s));
    rep(i, N) {
        if (s[i] == '.')
            w[i + 1] = 1;
    }

    rep(i, N) { b[i + 1] += b[i]; }
    rep(i, N) { w[i + 1] += w[i]; }
    reverse(all(w));

    ll ans = INF;
    rep(i, N + 1) {
        ll tmp = b[i] + w[i];
        ans = min(ans, tmp);
    }

    cout << ans << endl;
}