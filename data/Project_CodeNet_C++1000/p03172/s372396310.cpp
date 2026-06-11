#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repR(i,a,b)for(int i=a;i>=b;i--)
#define repA(i, a, n) for(int  i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define vec vector<int>
#define vecl vector<long long int>
#define sz(x) (int) (x).size()
#define f(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define el '\n'
#define c(m) cout<<"-1"<<endl
#define YY  cout<<"YES"<<endl
#define NY  cout<<"NO"<<endl
#define i(n) int n;cin>>n;int a[n];rep(i,n)cin>>a[i];
const int MOD=1000000007;
const int Nm=-MOD;
const int N=1000005;
typedef long long ll;
ll add(ll x, ll y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

ll mul(ll x, ll y)
{
    return (x * 1ll * y) % MOD;
}

ll binpow(ll x, ll y)
{
    ll z = 1;
    while(y)
    {
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

ll inv(ll x)
{
    return binpow(x, MOD - 2);
}

ll divide(ll x, ll y)
{
    return mul(x, inv(y));
}


ll fact[N];

void precalc()//factorial
{
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
}

ll C(ll n, ll k)//nCr
{
    return divide(fact[n], mul(fact[k], fact[n - k]));
}
ll dp[101][100001];

int main()
{ ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    tc=1;
  // cin>>tc;
    while(tc--)
    {
          f(dp);
          int pre[101];
          f(pre);
          int n,k;
          cin>>n>>k;
          int a[n];
          rep(i,n)
          {
          	cin>>a[i];
          	if(i==0)
          	pre[i]=a[i];
          	else
          	pre[i]=a[i]+pre[i-1];
          	
		  }
		
		          
		  for(int i=0;i<=a[0];i++)
		  dp[0][i]=1;
		  
		  repA(i,1,n-1)
		  { 
		  	for(int j=0;j<=k;j++)
		  	{ if(j==0)
		  	  {
		  	  	dp[i][j]=1;
		  	  	continue;
				}
		  		if(j>pre[i])
		  		dp[i][j]=0;
		  		else
		  		if(j==pre[i])
		  		{
		  		
		  			dp[i][j]=1;
				  }
		  		else
		  	{
				  (dp[i][j]=dp[i-1][j]+dp[i][j-1])%MOD;
				  if(j-1>=a[i])
				  {
				  	dp[i][j] = (dp[i][j] + MOD - dp[i-1][j - 1 - a[i]]) % MOD;
				  }
				  
			}
			if(dp[i][j] >= MOD){
                dp[i][j] = dp[i][j] % MOD;
            }
			  }
		  }
		  	
		  	
		////
			cout<<dp[n-1][k];
		  
    }

	return 0;
}


