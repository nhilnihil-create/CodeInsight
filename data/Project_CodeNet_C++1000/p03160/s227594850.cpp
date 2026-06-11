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
            ll i,j,n,m;
            ll mincost[N];
            ms(mincost,0);
            cin>>n;
            ll a[n];
            input(a,0,n);
            mincost[1] = abs(a[0]-a[1]);//a[0];
            fo(i,2,n)
            {
				mincost[i] = min(mincost[i-1]+abs(a[i]-a[i-1]),mincost[i-2]+abs(a[i-2]-a[i]));
			}
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
