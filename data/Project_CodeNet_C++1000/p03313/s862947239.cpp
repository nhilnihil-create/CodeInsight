#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define MOD2 998244353
#define pb emplace_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) (ll)x.size()
#define F first
#define S second
#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define ROF(i,a,b) for(ll i=a;i>=b;--i)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

ll mexp(ll a, ll b, ll m){
    ll ans=1;
    a%=m;
    while(b){
        if(b&1) ans=ans*a%m;
        b>>=1;
        a=a*a%m;
    }
    return ans;
}

const int N = (1<<18) + 1;

ll a[N];
ll dp1[N], dp2[N];

int main(){
    IOS
	int n;
	cin >> n;
	FOR(i,0,(1<<n)-1){
		cin >> a[i];
		dp1[i] = a[i];
	}
	FOR(i,0,n-1){
		FOR(mask,0,(1<<n)-1){
			if(mask & (1<<i)){
				if(dp1[mask ^ (1<<i)] > dp1[mask]){
					dp2[mask] = dp1[mask];
					dp1[mask] = dp1[mask ^ (1<<i)];
				}
				else if(dp1[mask ^ (1<<i)]  > dp2[mask]){
					dp2[mask] = dp1[mask ^ (1<<i)];
				}
				if(dp2[mask ^ (1<<i)] > dp2[mask]){
					dp2[mask] = dp2[mask ^ (1<<i)];
				}
			}
		}
	}
	ll ans = 0;
	FOR(i,1,(1<<n)-1){
		ans = max(ans, dp1[i] + dp2[i]);
		cout << ans << endl;
	}


    return 0;
}