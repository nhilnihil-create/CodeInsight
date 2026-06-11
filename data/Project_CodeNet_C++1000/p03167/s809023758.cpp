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




ll func(vector <vector <char> > &v,ll n,ll m,ll i,ll j,vector <vector <ll> > &dp) {
    if(i>=n || j>=m) return 0;
    if(v[i][j]=='#') return 0;
    if(dp[i][j]!=-1) return dp[i][j]%mod;
    if(i==n-1 && j==m-1) {
        dp[i][j]=1;
        return dp[i][j];
    }
    return dp[i][j]=(func(v,n,m,i+1,j,dp)+func(v,n,m,i,j+1,dp))%mod;
}




void cazz() {
    ll t=1,i=0,j,n;
    //cin>>t;
    while(t--) {
        ll m;
        cin>>n>>m;
        vector <vector <char> > v(n,vector <char> (m));
        fr(i,0,n)
            fr(j,0,m)
                cin>>v[i][j];
        vector <vector <ll> > dp(n,vector <ll> (m,-1));
        cout<<func(v,n,m,0,0,dp)%mod<<"\n";
    }
}




int main() {
    spdio;
	cazz();
	return 0;
}
