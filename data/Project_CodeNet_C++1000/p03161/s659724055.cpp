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
            
            
            cin>>n>>k;
            ll a[n];
            ll mincost[N];
            ms(mincost,0);
            input(a,0,n);
            
            fo(i,1,n)
            {
				ll minn = INT_MAX;
				for(j = i-1;j>=0&&j>=i-k;j--)
				{
					//if(i==n-1)
					//cout<<abs(a[i]-a[j])<<endl;
					minn = min(minn,mincost[j]+abs(a[j]-a[i]));//,mincost[i-2]+abs(a[i-2]-a[i]));
					
				}
				mincost[i] = minn;
			}
			//print(mincost,0,n);
             cout<<mincost[n-1]<<endl;
            
    
            
						            









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
