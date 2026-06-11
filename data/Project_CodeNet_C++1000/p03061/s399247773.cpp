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

    ll a[n];
    rep(i, n)cin >> a[i];

    ll gcd_l[n];
    ll gcd_r[n];
    gcd_l[0] = a[0];
    gcd_r[n-1] = a[n-1];

    rep(i, n-1){
        gcd_l[i+1] = Gcd(gcd_l[i], a[i+1]);
        gcd_r[n-2-i] = Gcd(gcd_r[n-1-i], a[n-2-i]);
    }

    ll ans = 1;
    rep(i, n){
        if(i == 0)ans = max(ans, gcd_r[1]);
        else if(i == n-1)ans = max(ans, gcd_l[n-2]);
        else {
            ans = max(ans, Gcd(gcd_l[i-1], gcd_r[i+1]));
        }
    }

    cout << ans << endl;
}