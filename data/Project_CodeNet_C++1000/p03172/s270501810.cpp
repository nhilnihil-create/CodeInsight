#include<bits/stdc++.h>
 
#define ll                    long long int
#define ll_MAX                LLONG_MAX
#define ll_MIN                LLONG_MIN
#define pi                    3.14159265358979323846
#define count_1(n)            __builtin_popcountll(n)
#define MOD                   1000000007
#define MAX                   1e9
#define MIN                   -1e9
#define itoc(c)               ((char)(((int)'0')+c))
#define mid(s,e)              (s+(e-s)/2)
const int MX=10010896;
const int lmt=3164;
const int N=10000001;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll modpow(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
#define print_upto(a,n)        for(int i=0;i<n;i++)    cout<<a[i]<<" "; cout<<endl
#define print(a)        for (auto x : a) cout << x << " "; cout << endl

inline void solve(){
    ll n,k;cin>>n>>k;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(k+1,1));
    for(ll j=1;j<=k;j++){
        dp[0][j]=0;
    }
    vector<ll> pref(k+1);
    for(ll i=1;i<=n;i++){
        vector<ll> pref(k+1);
        pref[0]=dp[i-1][0];
        for(ll j=1;j<=k;j++){
            pref[j]=( pref[j-1]%MOD+dp[i-1][j]%MOD )%MOD;
        }
        for(ll j=1;j<=k;j++){
            if(j<=a[i]){
                dp[i][j]=pref[j];
            }
            else{
                ll ignore_sm=pref[j-a[i]-1];
                dp[i][j]=((pref[j]%MOD-ignore_sm%MOD)+MOD)%MOD;
            }
            //cout<<"dp["<<i<<"]["<<j<<"]:"<<dp[i][j]<<endl;
        }
    }
    cout<<dp[n][k]<<"\n";
}

int main()
{
	cout<<fixed<<setprecision(12);
	fastio;ll  t=1,tc=1;
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	#endif
	//cin>>t;
	while(t--){solve();}return 0;
}