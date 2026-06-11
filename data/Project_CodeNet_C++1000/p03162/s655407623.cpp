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
        ll i,j,n,z;
        cin>>n;
        ll h[n][3],mh[n][3];
        for(i=0;i<n;i++)
        {
                 for(j=0;j<3;j++)
                 cin>>h[i][j];
        }
        mh[0][0]=h[0][0];
        mh[0][1]=h[0][1];
        mh[0][2]=h[0][2];
        for(i=1;i<n;i++)
        {
                 
                 for(j=0;j<3;j++)
                 {
                          ll ma=0;
                          for(z=0;z<3;z++)
                          {
                                   if(j==z)
                                   continue;
                                   ma=max(mh[i-1][z],ma);
                          }
                          mh[i][j]=ma+h[i][j];
                 }
        }
        ll ma=0;
        for(i=0;i<3;i++)
        {
             ma=max(ma,mh[n-1][i]);    
        }
        cout<<ma;
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