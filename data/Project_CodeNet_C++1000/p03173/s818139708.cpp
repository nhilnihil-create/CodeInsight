#include<bits/stdc++.h>
#define ll long long int
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define rep(i,a,n)   for(int i=a;i<n;i++)
#define pb           push_back
#define ff           first
#define ss           second
#define lcm(a, b)    ((a)*((b)/gcd(a,b)))
#define all(v)       v.begin(),v.end()
#define rall(v)      v.rbegin(),v.rend()
#define Pi           2*acos(0.0)
#define pii          pair<int,int>
#define pll          pair<ll,ll>
#define mem(a,b)     memset(a, b, sizeof(a))
#define fill_(a,b)   fill(a,a+n,b);
using namespace std;

ll expo(ll a,ll b,ll m = mod){
	a%=mod;
	ll res = 1;
	while(b){
		if(b&1)
			res = (res*a)%m;
		a = (a*a)%m;
		b>>=1;
	}
	return res;
}
ll gcd(ll a,ll b){
	while(b>0){
		ll r = a%b;
		a = b; b = r;
	}
	return a;
}
const ll INF = 1e18L + 5;
int main()
{
	 
   boost
   #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t=1;
// 	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    ll a[n+1];
	    ll pre[n+1];
	    pre[0] = 0;
	    rep(i,1,n+1){
	        cin>>a[i];
	        pre[i]=pre[i-1]+a[i];
	    }
	    ll dp[n+1][n+1];
	    mem(dp,0);
	    for(int i=1;i<n;i++)
	    dp[i][i+1] = a[i]+a[i+1];
	    for(int l=3;l<=n;l++){
	        for(int i=1;i<=n-l+1;i++){
	            int j = i+l-1;
	            dp[i][j] = INF;
	            for(int k=i;k<j;k++){
	                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+pre[j]-pre[i-1]);
	            }
	        }
	    }
	    cout<<dp[1][n]<<"\n";
	}

    return 0;
}
