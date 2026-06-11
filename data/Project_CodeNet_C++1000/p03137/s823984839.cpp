#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    ll n, m; cin >> n >> m;
    V<ll> x(m);
    for(int i = 0; i < m; i++) cin >> x[i];
    sort(ALL(x));

    V<ll> x2;
    for(int i = 0; i < m - 1; i++){
        x2.push_back(x[i + 1] - x[i]);
    }
    sort(ALL(x2));

    ll ans = 0;
    for(int i = 0; i < (int)x2.size() - (n - 1); i++){
        ans += x2[i];
    }
    cout << ans << endl;

}
