#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll d, g;
    cin >> d >> g;
    vector<ll> p(d), c(d);
    for(int i=0;i<d;i++) cin >> p[i] >> c[i];

    ll ans = INF;
    ll maki = (1LL << d);
    for(int bit = 0; bit < maki; bit++){
    	ll id = -1;
    	ll cnt = 0;
    	ll num = 0;
    	ll cost = 0;
    	for(int i=0;i<d;i++){
    		if(bit >> i & 1){
    			num += p[i] * (i+1) * 100 + c[i];
    			cost += p[i];
    		}else{
    			id = 100LL * (i+1);
    			cnt = p[i];
    		}
    	}
    	if(num < g){
    		ll pos = (g - num + id - 1)/ id;
    	    if(pos <= cnt) {
    	    	num = g;
    	    	cost += pos;
    	    }
    	}
    	if(num < g) continue;
    	ans = min(ans, cost);

    }
    cout << ans << endl;
    return 0;
}
