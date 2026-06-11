#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

struct idx{
    ll ap, bp, cp;
};

int main(){
    ll x, y, z, k;
    cin >> x >> y >> z >> k;

    vector<ll> a(x), b(y), c(z);
    rep(i, x)cin >> a[i];
    rep(i, y)cin >> b[i];
    rep(i, z)cin >> c[i];

    vector<ll> a_b;
    rep(i, x)rep(j, y){
        a_b.push_back(a[i]+b[j]);
    }

    sort(ALL(a_b), greater<ll>());
    vector<ll> ans;
    rep(i, min(k, (ll)a_b.size()))rep(j, z){
        ans.push_back(a_b[i]+c[j]);
    }

    sort(ALL(ans), greater<ll>());
    rep(i, k)cout << ans[i] << endl;
}