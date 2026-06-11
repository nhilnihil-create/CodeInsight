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
double dp[301][301][301];

double diceThrow(int  x,int  y,int  z,int  n)
{
	if(x==0 && y==0 && z==0) return 0;
	if(x<0 || y<0 || z<0) return 0;
	if(dp[x][y][z]>-0.9) return dp[x][y][z];
	else
	{
		double ans=n+x*diceThrow(x-1,y,z,n)+y*diceThrow(x+1,y-1,z,n)+z*diceThrow(x,y+1,z-1,n);
		ans=ans/(x+y+z);
		return dp[x][y][z]=ans;		
	}
}




int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,i,j,k;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    int x,y,z;
    x=y=z=0;
    for(i=0;i<n;i++)
    {
    	if(a[i]==1) x++;
    	if(a[i]==2) y++;
    	if(a[i]==3) z++;
    }
    memset(dp,-1,sizeof(dp));
    cout<<pre(diceThrow(x,y,z,(double)n),9)<<endl;

	return 0;
}
