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
  string a,b;
  cin>>a>>b;
  int n=a.length(),m=b.length();
  vector<vi> dp(n+1,vi(m+1));

  loop(i,0,n)
  {
    loop(j,0,m)
    {
      if(i==0 || j==0)
        dp[i][j]=0;
      else if(a[i-1]==b[j-1])
      {
        dp[i][j]=1+dp[i-1][j-1];
      }
      else
      {
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }

  string ans="";
  int i=n,j=m;

  while(i>0 && j>0)
  {
    if(a[i-1]==b[j-1])
    {
      ans+=a[i-1];
      i--,j--;
    }
    else if(dp[i][j-1]>dp[i-1][j])
    {
      j--;
    }
    else
      i--;

  }

  reverse(all(ans));
  cout<<ans<<endl;

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
