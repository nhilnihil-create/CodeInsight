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
    ll n;
    cin >> n;

    ll ans;
    rep(i, n){
        ll a;
        cin >> a;
        if(i == 0)ans = a;
        else ans = Gcd(ans, a);
    }

    cout << ans << endl;
}