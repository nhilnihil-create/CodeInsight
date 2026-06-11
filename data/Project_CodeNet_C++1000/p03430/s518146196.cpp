#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define mod 998244353 
#define pb push_back
//#define mp make_pair
#define INF 2000000011LL
#define INFLL 1000000000000000011LL
#define eps 1e-9
#define pp pair < pair<ll,ll> , ll> 
#define fo(i,j,k) for(int i=j;i<=k;i++)
#define foll(i,j,k) for(ll i=j;i<=k;i++)
#define clr(a) memset(a,0,sizeof(a))
#define vi vector<int>
#define vll vector<ll>
#define sz(a) a.size()
#define len(a) a.length()
#define all(a) a.begin(),a.end()
#define io_file freopen("Contest/input_file.in", "r", stdin); freopen("Contest/output_file.in", "w", stdout)

const int MAXN = 2e5+5;
using namespace std;
ll power(ll x, ll y)
{
  ll res = 1;
  while(y>0)
  {
    if(y&1)
       {
         res = (res*x)%mod;
        }
     x = (x*x)%mod;
     y = y>>1;
  }
    return res;
}
// std::vector<ll> divi[100004];
// void divisor(int n)
// {
//    for(ll i=1;i<=n;i++)
//    {
//      for(ll j=i;j<=n;j+=i)
//      {
//        divi[j].pb(i);
//      }
//    }
// }

string s;
int K;
int dp[305][305][305];

ll solve(int i, int j, int k)
{
	if(i > j) return 0;
	if(i==j) return dp[i][j][k]=1;
	if(dp[i][j][k]!=-1) return dp[i][j][k];
	if(i+1==j){
		if(s[i]==s[j])
		{
			return dp[i][j][k] = 2;
		}
		else {
			if(k==0)
				return dp[i][j][k] = 1;
			else  if(k > 0) return dp[i][j][k] = 2;
		} 
	}
	ll ans=max(solve(i+1,j,k),solve(i,j-1,k));
	if(s[i]==s[j])
	{
		ans  = max(ans, 2 + solve(i+1,j-1,k));
	
	}
	else if(k>0){
		ans = max(ans,2 + solve(i+1,j-1,k-1));
	}
	return dp[i][j][k] =  ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>s;
    cin>>K;
    
    cout<<solve(0,s.length()-1,K)<<endl;
    return 0;

}
	