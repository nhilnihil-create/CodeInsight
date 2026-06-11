#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define all(sdk) sdk.begin(),sdk.end()
#define mll map<ll, ll>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repd(i,a,b) for(ll i=a;i>=b;--i)
//#define mp make_pair
#define hell 1000000007
#define endl '\n'
#define vvll vector<vector<int> >
#define vll vector<int>
#define mint map<int,int>
#define sz(x) (int)x.size()
#define sll set<int>
#define pll pair<int,int>
#define F first
#define S second
#define INF 1e18
#define NINF -1e16

#define maxn 100005
int spf[maxn];
vll primes,prev[maxn],next[maxn];
set<int>s;
void sieve()
{
	rep(i,2,maxn)
	{
		if (spf[i]==0)
		{
			spf[i]=i;
			for(int j=2*i;j<=maxn;j+=i)
			{
				if(spf[j]==0)
					spf[j]=i;
			}
		}
	}
}
void SieveOfEratosthenes(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    }
    for (int p=2; p<=n; p++) 
    {
        if (prime[p]) 
        {
            primes.pb(p); 
            s.insert(p);
        }
    }    
} 
// bool isPrime(ll n) 
// { 
//     if (n <= 1) 
//         return false; 
//     if (n <= 3) 
//         return true; 
//     if (n % 2 == 0 || n % 3 == 0) 
//         return false; 
//     for (int i = 5; i * i <= n; i = i + 6) 
//         if (n % i == 0 || n % (i + 2) == 0) 
//             return false; 
//     return true; 
// } 
// ll power(ll x,ll y)
// {
//     ll X=x;
//     //X=X%p;//if x is greater than p
//     if(X==0)
//     {
//         return 0;
//     }
//     ll res=1ll;
//     while(y>0)
//     {
//         if(y&1)
//         {
//             res=((res)*(X));
//             y--;
//         }
//         y=y>>1;
//         X=((X)*(X));
//     }
//     // res=(res>=0)?(res%p):(res+p)%p;
//     return(res);
// }
// void dfs(int u, int par){
//     cnt[u] = 1;
//     p[u] = par;
//     for(int i : g[u]){
//         if(i != par){
//             dfs(i,u);
//             cnt[u] += cnt[i];
//         }
//     }
// }
// int children(vll v[],int parent,int src,vll& chil)
// {
// 	int ans =0;
// 	for(auto it:v[src])
// 	{
// 		if(it!=parent)
// 		{
// 			ans+= 1+children(v,src,it,chil);
// 		}
// 	}
// 	chil[src] = ans;
// 	return ans;
 
// }
bool cmp(const pair<int,int>&a,const pair<int,int>&b)
{
    if (a.F==b.F)
    return a.S<b.S;
    else
    return a.F>b.F;
}

signed main() {
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand (static_cast <unsigned> (time(0)));
// 	SieveOfEratosthenes(100005); 
// 	sort(all(primes));
    sieve();
	int t=1;
	//cin >> t;
	while (t--) 
	{
	    int n;
	    cin >> n;
	    vll h(n);
	    rep(i,0,n)
	    cin >> h[i];
	    vll dp(n,INT_MAX);
	    dp[0]=0;
	    rep(i,0,n)
	    {
	        rep(j,i+1,i+3)
	        {
	            if(j<n)
	            dp[j]=min(dp[j],dp[i]+abs(h[i]-h[j]));
	        }
	        
	    }
	    cout<<dp[n-1]<<endl;
	}
	return 0;
}