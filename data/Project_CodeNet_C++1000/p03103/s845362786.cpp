#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    ll n, m;
    cin >> n >> m;
    vector<P> v;
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    ll ans = 0;
    int i = 0;
    while(m > 0){
        int num = min(m, v[i].second);
        ans += v[i].first * num;
        m -= num;
        i++;
    }

    cout << ans << endl;

    return 0;
}
