/* ****AWARE**** */
#include<bits/stdc++.h>
#include <limits.h> 
#define cut ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll          long long
#define pb          push_back
#define endl        '\n'
#define pii         pair< ll, ll>
#define vi          vector< ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(  ll i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp13       make_pair
using namespace std; 
#define MAX  3000
#define MODULO 2
using namespace std;   
#define hell 1000000007 
#define hell1 30000000000000000
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
#define mysizeof(i) (char*)(&i+1)-(char *)(&i);
ll T;
//double dp[MAX][MAX];
vector<double>v;

void solve()
{    ll i,j,k,n,m,x=0,y=0,z=0;
     cin>>n;
     double a,b,c,d;
     for(i=0;i<n;i++)
     { cin>>a,v.pb(a);
     	
     	if(a==1)
     		x++;
     	else if(a==2)
     		y++;
     	else if(a==3)
     		z++;

     }
double dp[n+1][n+1][n+1];
for(k=0;k<=z;k++)
{
	for(j=0;j<=min(n,y+z-k) ;j++)
	{
		for(i=0;i<=min(n,x+y+z-k-j);i++)
		{   if(i==0 && j==0 && k==0)
			{
			   dp[i][j][k]=0;	
			   continue;
			}
			a=(((n-i-j-k)*(1.0))/n);
			if(a<0)
			continue;
			b=((i*(1.0))/n);
            c=((j*(1.0))/n);
            d=((k*(1.0))/n);
            dp[i][j][k]=1;
            if(b!=0)
            dp[i][j][k]+=b*dp[i-1][j][k];
           if(c!=0)
           	dp[i][j][k]+=c*dp[i+1][j-1][k];
           if(d!=0)
           	dp[i][j][k]+=d*dp[i][j+1][k-1];
            dp[i][j][k]=((dp[i][j][k])*(1.0))/(1-a);

		}
	}
}

cout<<fixed<<setprecision(11)<<dp[x][y][z]<<"\n";
  
}
           
int main(){ 
cut; 
ll t; 
//cin>>t;
//T=t;
 t=1;
while(t--)
solve();
return 0;
}
     
