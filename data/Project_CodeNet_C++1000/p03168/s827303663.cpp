#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int long long
#define pb push_back
#define mod 1000000007
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define inf 1e18
#define pre(x,y) fixed<<setprecision(y)<<x
#define pq priority_queue<int>
#define mpq priority_queue<int,vector<int>,greater<int>>
#define gcd(x,y) __gcd(x,y)
#define mp make_pair

double dp[3000][3000];

double cointoss(double a[],int n,int i,int j)
{
	if(i+j>n) return 0;
	if(i+j==n && i>j)  return 1;
	else if(i+j==n && j>i) return 0;
	else if(dp[i][j]!=-1) return dp[i][j];
	else
	{
		dp[i][j]=a[i+j]*cointoss(a,n,i+1,j)+(1-a[i+j])*cointoss(a,n,i,j+1);
		return dp[i][j];
	}

}



int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,i,j;
    cin>>n;
    double a[n];
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<=n;i++)
    {
    	for(j=0;j<=n;j++) dp[i][j]=-1;
    }
    cout<<pre(cointoss(a,n,0,0),9)<<endl;
	return 0;
}
