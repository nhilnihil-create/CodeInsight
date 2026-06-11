#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
const int N = 1e5 + 10;
const double eps = 1e-9;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, pair<ll, ll>>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second.first >> v[i].second.second;
    }
    ll ans = 0;
    for (ll i = -1; i <= 1; i += 2) {
        for (ll j = -1; j <= 1; j += 2) {
            for (ll k = -1; k <= 1; k += 2) {
                vll nw;
                for (int l = 0; l < n; ++l) {
                    nw.push_back(i * v[l].first + j * v[l].second.first + k * v[l].second.second);
                }
                sort(all(nw), greater<ll>());
                ll tm = 0;
                for (int l = 0; l < m; ++l) {
                    tm += nw[l];
                }
                ans = max(ans, tm);
            }
        }
    }
    cout << ans << endl;
}