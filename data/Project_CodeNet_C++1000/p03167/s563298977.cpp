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
            cin>>n>>m;
            ll ans[n+1][m+1];
            ms(ans,0);
            char a[n][m];
            fo(i,0,n)
            {
				fo(j,0,m)
				{
					cin>>a[i][j];
				}
			}
			ans[1][1] = 1;
			fo(i,1,n+1)
			{
				fo(j,1,m+1)
				{
					if(i==1&&j==1)
					 continue;
			
					if(a[i-1][j-1]!='#')
					{
						ans[i][j] = (ans[i-1][j] + ans[i][j-1])%MOD;
					}
				}
			}
			cout<<ans[n][m]<<endl;
			
				    
            
        
    
            
						            









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
