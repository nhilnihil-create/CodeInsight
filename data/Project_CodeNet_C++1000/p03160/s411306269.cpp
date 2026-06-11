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



ll fun(ll h[],ll i,ll n,vector <ll> &dp) {
    if(i>=n-1) return 0;
    if(dp[i]!=-1) return dp[i];
    if(i==n-2) return dp[i]=fun(h,i+1,n,dp)+abs(h[i+1]-h[i]);
    else return dp[i]=min(fun(h,i+1,n,dp)+abs(h[i+1]-h[i]),fun(h,i+2,n,dp)+abs(h[i+2]-h[i]));
}




void cazz() {
    ll t=1,i=0,j,n;
    //cin>>t;
    while(t--) {
        cin>>n;
        ll h[n];
        fr(i,0,n) cin>>h[i];
        vector <ll> dp(n+1,-1);
        cout<<fun(h,0,n,dp)<<"\n";
    }
}




int main() {
    spdio;
	cazz();
	return 0;
}
