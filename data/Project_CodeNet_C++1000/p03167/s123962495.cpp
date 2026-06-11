/****************************************************************************
Is this the real life? Is this just fantasy?
Caught in a landslide, no escape from reality
Open your eyes, look up to the skies and see
I'm just a poor boy, I need no sympathy
Because I'm easy come, easy go, little high, little low
Any way the wind blows doesn't really matter to me, to me!!!
--------------------------------------------------
CP is quite cool.It becomes cooler when you enjoy learning new things
******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define endl "\n"
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define pool(i,a,b) for(int i=a;i>=b;i--)
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vll vector<ll>
#define vb vector<bool>
#define all(x) x.begin(),x.end()
#define sz(a) a.size()
#define ff first
#define ss second
#define debug(x) cout<<#x<<" = "<<x<<endl;
const int mod=1e9+7;

void solve()
{
  int h,w;
  cin>>h>>w;
  ll dp[h][w];
  dp[0][0]=1;

  rep(i,h)
  {
    rep(j,w)
    {
      char c;
      cin>>c;
      if(i!=0 || j!=0)
      {
        dp[i][j]= ( (i-1>=0)?dp[i-1][j]:0 )+ ( (j-1>=0)?dp[i][j-1]:0 );
        dp[i][j]%=mod;          
      }

      if(c=='#')
        dp[i][j]=0;
    }
  }


  h--;w--;
  cout<<dp[h][w]<<endl;
} 

int main()
{

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  ios::sync_with_stdio(false);
  cin.tie(0);

  int t=1;
  // cin>>t;
  while(t--)
  {
    solve();
  }

  return 0;
}
