#include<bits/stdc++.h>
#define ll long long int
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
const int mod = 1e9 + 7;
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

void add_self(int &a,int b){
    a+=b;
    if(a>=mod) a-=mod;
}

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
		bool can[n][n];
		for(int i=0;i<n;i++){
		    for(int j=0;j<n;j++){
		        cin>>can[i][j];
		      //  cout<<can[i][j]<<" ";
		    }
		  //  cout<<endl;
		}
		int dp[1<<n];
		mem(dp,0);
		dp[0] = 1;
		    for(int mask = 0; mask < (1<<n); mask++){
		        int a = __builtin_popcount(mask);
		        for(int b=0;b<n;b++){
		            if(can[a][b] && !(mask&(1<<b))){
		                int m2 = mask|(1<<b);
		                add_self(dp[m2],dp[mask]);
		              //  cout<<dp[m2]<<" ";
		            }
		        }
		    }
		
		cout<<dp[(1<<n)-1]<<"\n";
	}
    return 0;
}
