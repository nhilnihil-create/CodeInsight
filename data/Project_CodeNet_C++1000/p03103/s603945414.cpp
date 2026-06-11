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

vector<P> vp;

int main(){
    int n, m;
    cin >> n >> m;
    rep(i, n){
        ll a, b;
        cin >> a >> b;
        vp.push_back({a,b});
    }
    sort(vp.begin(), vp.end());
    
    ll cnt = 0;
    ll ans = 0;

    rep(i, n){
        if (cnt + vp[i].second <= m){
            ans += vp[i].first * vp[i].second;
            cnt += vp[i].second;
        }
        else {
            ans += vp[i].first * (m - cnt);
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
