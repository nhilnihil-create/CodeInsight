#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

ll Gcd(ll a,ll b){
    if(a < b)swap(a, b);

	if(a%b == 0)return(b);

	else return(Gcd(b, a%b));
}

int main(){
    ll n, x;
    cin >> n >> x;
    ll dist[n];
    rep(i, n){
        ll x_i;
        cin >> x_i;
        dist[i] = abs(x - x_i);
    }

    ll ans = dist[0];
    for(ll i = 1; i < n; ++i){
        ans = Gcd(ans, dist[i]);
    }

    cout << ans << endl;
}