#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define mod (ll)(1e9+7)
#define INF (ll)(1e9)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
int gcd(int A,int B) {if(!B)return A;return gcd(B,A%B);}
int dp[10005][5005];
int c[10]={0,2,5,5,4,5,6,3,7,6};
bool can[10];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		can[x] = 1;
		}
	for(int i=0;i<=n;i++)
	    for(int j=0;j<=5000;j++)
	       dp[i][j] = -1;
	
	int bestj = 0;
	dp[0][0] = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5001;j++)
		{
			for(int k=9;k>0;k--)
			{
				if(!can[k] || i - c[k] < 0)continue;
				{
				   if(dp[i - c[k]][j-1] == -1)continue;
				   dp[i][j] = k;	
				   if(i == n)bestj = max(bestj,j);
				   break;
				}				
			}		
		}	
	}
	while(bestj)
	{
		cout<<dp[n][bestj];
		n-=c[dp[n][bestj]];
		bestj--;
	}
	
}
