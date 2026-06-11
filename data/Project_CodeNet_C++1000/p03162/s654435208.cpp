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




ll ncr(ll n,ll r) {
    ll val=1,i,j,p=2;
    rfr(i,n-r+1,n+1) {
        val*=i;
        while(val%p==0 && p<=r) {
            val/=p;
            p+=1;
        }
    }
    if(p<r) {
        fr(i,p,r+1) val/=i;
    }
    return val;
}



ll fun(ll n,ll i,ll j,ll a[][3],vector <vector <ll> > &dp) {
    if(i>=n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    ll k,val=-inf;
    fr(k,0,3) {
        if(k==j) continue;
        val=max(val,a[i][j]+fun(n,i+1,k,a,dp));
    }
    return dp[i][j]=val;
}




void cazz() {
    ll t=1,i=0,j,n;
    //cin>>t;
    while(t--) {
        cin>>n;
        ll a[n][3];
        fr(i,0,n) {
            fr(j,0,3) cin>>a[i][j];
        }
        vector <vector <ll> > dp(n+1,vector <ll> (3,-1));
        fun(n,0,0,a,dp);
        fun(n,0,1,a,dp);
        fun(n,0,2,a,dp);
        cout<<max(dp[0][1],max(dp[0][2],dp[0][0]))<<"\n";
    }
}




int main() {
    spdio;
	cazz();
	return 0;
}
