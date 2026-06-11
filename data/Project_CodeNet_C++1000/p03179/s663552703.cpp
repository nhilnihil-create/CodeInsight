#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pp pair<ll,ll>
#define ppp pair<ll,pp >
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define ld long double
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for(ll i=a;i<b;i+=1)
#define sz(v) (ll)(v.size())
#define hell (ll)1000000007
#define slld(x) scanf("%lld",&x)
ll t=1, tt;
const ll N=100005;
inline ll mult(ll x,ll y){x%=hell;y%=hell;return (1LL*x*y)%hell;}
inline ll add(ll x,ll y){x+=y;return x%hell;}
inline ll powMod(ll base,ll expo){
	if(base==0)return 0;
	ll ans=1;
	while(expo){
		if(expo&1)ans=mult(ans,base);
		base=mult(base,base); 
		expo>>=1;
	}
	return ans;
}
void solve(){
	ll n, x, L, R, dp[2][3005];
	string s;
	cin>>n>>s;
	dp[1][1]=1;
	rep(len,2,n+1){
		vector<ll> pref(n+2,0);
		x=len&1;
		rep(i,1,len+1){
			pref[i]=add(pref[i-1],dp[x^1][i]);
			dp[x][i]=0;
		}
		rep(j,1,len+1){
			if(s[len-2]=='<'){
				L=1;
				R=j-1;
			} else {
				L=j;
				R=len-1;
			}
			dp[x][j]=add(dp[x][j],add(pref[R],hell-pref[L-1]));
		}
	}
	ll ans=0;
	rep(i,1,n+1)ans=add(ans,dp[n&1][i]);
	cout<<ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   	//cin>>t;
   	tt=t;
    while(t--){
        solve();
        if(t)cout<<"\n";
    }
    return 0 ;
}
