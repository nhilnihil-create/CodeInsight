
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define vi vector<int>
#define vl vector<long long>
#define vvi vector<vector<int>>
#define fin(ar,k,n) for(int i=k;i<n;i++) cin>>ar[i]
#define fout(ar,k,n) for(int i=k;i<n;i++) cout<<ar[i]<<' '
#define all(z) z.begin(),z.end()
#define mcc ((int)1e9+7)
#define mcf 998244353
#define mi map<int,int>
#define mem(a,n) memset(a,n,sizeof(a))
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> fst;

const int N=307;
double dp[N][N][N];
int n,c[4];
void solve()
{
	cin>>n;
	for (int i=0;i<n;i++)
	{
		int x; cin>>x;
		c[x]++;
	}
	for (int k=0;k<=c[3];k++)
	{
		for (int j=0;j<=c[3]+c[2]-k;j++)
		{
			for (int i=0;i<=c[3]+c[2]+c[1]-j-k;i++)
			{
				if (i+j+k==0) continue;
				if(i) dp[i][j][k]+=i*1.0*dp[i-1][j][k];
				if(j) dp[i][j][k]+=j*1.0*dp[i+1][j-1][k];
				if(k) dp[i][j][k]+=k*1.0*dp[i][j+1][k-1];
				dp[i][j][k]+=n+0.0;
				dp[i][j][k]/=1.0*(i+k+j);
			}
		}
	}
	printf("%.12lf",dp[c[1]][c[2]][c[3]]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}