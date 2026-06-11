#include <bits/stdc++.h>
#define ll long long int
#define mod 998244353 
#define pb push_back
//#define mp make_pair
#define INF 2000000011LL
#define INFLL 1000000000000000011LL
#define eps 1e-9
#define pp pair < pair<ll,ll> , ll> 
#define fo(i,j,k) for(int i=j;i<=k;i++)
#define foll(i,j,k) for(ll i=j;i<=k;i++)
#define clr(a) memset(a,0,sizeof(a))
#define vi vector<int>
#define vll vector<ll>
#define sz(a) a.size()
#define len(a) a.length()
#define all(a) a.begin(),a.end()
#define io_file freopen("Contest/input_file.in", "r", stdin); freopen("Contest/output_file.in", "w", stdout)

const int MAXN = 2e5+5;
using namespace std;
ll power(ll x, ll y)
{
  ll res = 1;
  while(y>0)
  {
    if(y&1)
       {
         res = (res*x)%mod;
        }
     x = (x*x)%mod;
     y = y>>1;
  }
    return res;
}
// std::vector<ll> divi[100004];
// void divisor(int n)
// {
//    for(ll i=1;i<=n;i++)
//    {
//      for(ll j=i;j<=n;j+=i)
//      {
//        divi[j].pb(i);
//      }
//    }
// }



ll n;
string a[305];
map<ll,ll>m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    ll ans = 0;
    // cout<<"hi"<<endl;
    for(int x=1-n;x<=n-1;x++)
    {
      bool flag = true;
      // cout<<"hihi"<<endl;
      for(int i=0;i<n;i++)
      {
        for(int j = 0;j<n;j++)
        {
          // int xind = (j-x + n)%n;
          // int yind = (i+x + n)%n;
          // if(x==1)
          //   cout<<i<<" "<<j<<" "<<xind<<" "<<yind<<endl;
          if(a[i][j]!=a[(j-x + n)%n][(i+x + n)%n])
          {
            flag = false;
            break;
          }
        }
        if(!flag)
          break;
      }
      if(flag)
      {
        m[x] = 1;
        // cout<<x<<" ";
        
      }
    }
    for(int i=0;i<n;i++)
    {
      for(int j = 0;j<n;j++)
      {
        if(m[i-j]==1)
          ans++;
      }
    }
    cout<<ans<<endl;
    return 0;

}

