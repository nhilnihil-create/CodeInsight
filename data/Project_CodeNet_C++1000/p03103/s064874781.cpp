#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, int>> v;
    rep(i, n) {
        ll a;
        int b;
        cin >> a >> b;
        v.emplace_back(pair(a, b));
    }
    sort(all(v));
    ll prc = 0, sum = 0;
    rep(i, n) {
        sum += v[i].second;
        if (sum < m) {
            prc += v[i].first * v[i].second;
        } else {
            ll diff = sum - m;
            prc += v[i].first * (v[i].second - diff);
            break;
        }
    }
    cout << prc << "\n";
}