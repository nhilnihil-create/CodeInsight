#include<bits/stdc++.h>

typedef   long long  int ll;
typedef  long double ld;
typedef std::vector<ll> vi;
typedef std::vector<std::vector<ll> > vv;

#define MOD 1000000007
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,a,b) for(i=a;i<b;i++)
#define mp make_pair
#define pb(x) push_back(x)
#define fi first
#define se second
#define print(vec,a,b) for(ll i=a;i<b;i++) cout<<vec[i]<<" ";cout<<endl;
#define all(a) a.begin(),a.end()
#define input(vec,a,b) for(ll i = a;i<b;i++) cin>>vec[i];
#define ms(a,val) memset(a,val,sizeof(a))
using namespace std;

const int N = 1e5 + 5;


void solve(){
            ll i,j,n,m,k;
            
            
            cin>>n;
            ll dp[n][3];
            ms(dp,0);
            ll a[n][3];
            fo(i,0,n)
            {fo(j,0,3)
				cin>>a[i][j];
			}
			fo(i,0,3)
			dp[0][i] = a[0][i];//,dp[1] = a[1],dp[2]  =a[2];
			fo(i,1,n)
			{
				fo(j,0,3)
				{
					//dp[i][j] = INT_MAX;
					fo(k,0,3)
					{
						if(j^k)
						 dp[i][j] = max(dp[i][j],dp[i-1][k] + a[i][j]);
					 }
				 }
			 }
			 ll minn =  INT_MIN;
			 fo(i,0,3)
			  minn = max(minn,dp[n-1][i]);
			  cout<<minn<<endl;
            
    
            
						            









}

int main()
{
    IO;
      ll t=1;
      //cin>>t;


      while(t--)
      {

          solve();
      }
    return 0;
}
