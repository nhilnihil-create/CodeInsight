#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int mod = 1e9+7;
const int mx = INT_MAX;
const long double pi = 4*atan((long double)1);
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define file "orz"
const int mxN = 2e3+5;
int n,total,arr[mxN];
bool dp[mxN][100005];
signed main()
{
    //freopen(file".inp","r",stdin);
    //freopen(file".out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>arr[i];
		total+=arr[i]; 	
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=100000;j++)
		{
			dp[i][j]|=dp[i-1][abs(j-arr[i])];
			if(arr[i]+j<=100000)
				dp[i][j]|=dp[i-1][j+arr[i]];
		}
	}
	for(int i=0;i<=100000;i++)
		if(dp[n][i])
			return cout<<((total+i)>>1),0;
}
