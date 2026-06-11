//




#include <bits/stdc++.h>
using namespace std;


#define spdio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define pp pop_back()
#define pf push_front
#define ppf pop_front()
#define ff first
#define ss second
#define mp make_pair
#define fr(i,j,n) for(ll i=j; i<n; i++)
#define rfr(i,j,n) for(ll i=n-1; i>=j; i--)
#define pll pair<ll,ll>
#define plb pair<ll,bool>
#define psl pair<string,ll>
#define psb pair<string,bool>
#define srt(v) sort((v).begin(),(v).end())
#define ub(v,val) upper_bound((v).begin(),(v).end(),(val))-(v).begin()
#define lb(v,val) lower_bound((v).begin(),(v).end(),(val))-(v).begin()


typedef long double ld;
typedef long long int ll;


//getline(cin,string);
const ll inf = (ll) 1e18 + 19;
const ll mod = (ll) 1e9  +  7;




ll dfs(vector <ll> v[],vector <ll> &dp,ll node) {
    ll mx=-inf;
    if(dp[node]!=-1) return dp[node];
    if(v[node].size()==0) return 0;
    for(auto it: v[node]) {
        mx=max(mx,dfs(v,dp,it));
    }
    return dp[node]=1+mx;
}




void cazz() {
    ll t=1,i=0,j,n;
    //cin>>t;
    while(t--) {
        ll m;
        cin>>n>>m;
        vector <ll> v[n+1];
        ll a,b;
        fr(i,0,m) {
            cin>>a>>b;
            v[a].pb(b);
        }
        ll mx=-inf;
        vector <ll> dp(n+1,-1);
        fr(i,1,n+1) {
            mx=max(mx,dfs(v,dp,i));
        }
        cout<<mx<<"\n";
    }
}




int main() {
    spdio;
	cazz();
	return 0;
}
