#include <bits/stdc++.h>
#include <utility>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    ll n, m; cin >> n >> m;
    V<V<ll> > v(n + 1);
    V<P<ll, ll> > w(m);
    for(int i = 0; i < m; i++){
        ll p, y; cin >> p >> y;
        v[p].push_back(y);
        w[i] = make_pair(p, y);
    }

    map<ll, ll> x;
    for(int i = 1; i <= n; i++){
        sort(all(v[i]));
        for(int j = 0; j < v[i].size(); j++){
            x[v[i][j]] = j + 1;
        }
    }

    for(int i = 0; i < m; i++){
        int a = w[i].first;
        int b = x[w[i].second];
        printf("%06d", a);
        printf("%06d", b);
        cout << "\n";
    }

}
