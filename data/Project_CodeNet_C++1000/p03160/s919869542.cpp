#include<bits/stdc++.h>
#define MOD 1000000007
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define forf(i,a,b) for(i=a;i<b;i++)
#define forr(i,a,b) for(i=a;i>b;i--)
#define mp make_pair
#define f first
#define s second
#define pb(x) push_back(x)
typedef  long long  int ll;
typedef std::vector<ll> vi;

#define input(vec,a,b) for(ll i =a;i<b;i++) cin>>vec[i]
#define print(vec,a,b) for(ll i=a;i<b;i++) cout<<vec[i]<<" " ;cout<<endl;
#define all(a) a.begin(),a.end()
using namespace std;


void solve(){
        ll i,n;
        cin>>n;
        ll h[n],c[n];
        for(i=0;i<n;i++)
        cin>>h[i];
        c[0]=0;
        c[1]=abs(h[0]-h[1]);
        for(i=2;i<n;i++)
        {
                 c[i]=min(c[i-1]+abs(h[i]-h[i-1]),c[i-2]+abs(h[i]-h[i-2]));
        }
        cout<<c[n-1];
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