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
  int n;
  cin>>n;
  double dp[n+1][n+1],a[n+1],ans=0.0;
  memset(dp,0.0,sizeof(dp));
  
  rep(i,n+1)
    cin>>a[i+1];
  dp[0][0]=1.0;
  loop(i,1,n)
  {
    loop(j,0,i)
    {
      if(j!=0)
        dp[i][j]=dp[i-1][j-1]*a[i]+dp[i-1][j]*(1-a[i]);
      else
        dp[i][j]=dp[i-1][j]*(1-a[i]);
    }
  }


  loop(i,n/2+1,n)
  {
    ans+=dp[n][i];
  }

  printf("%.14f\n",ans);

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
