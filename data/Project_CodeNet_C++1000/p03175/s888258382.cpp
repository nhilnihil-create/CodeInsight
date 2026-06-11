#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define all(a) (a).begin(),(a).end()
#define X first
#define Y second
#define inf 1e18+5
using namespace std;
const int mod=1e9+7;
const int N=1e5+5;
int dp[N][2];
vi v[N];
void dfs(int t,int p)
{
    int cnt_b=1,cnt_w=1;
    for(int i=0;i<v[t].size();i++)
    {
        int ch=v[t][i];
        if(ch==p)continue;
        dfs(ch,t);
        cnt_b*=dp[ch][1];
        cnt_w*=(dp[ch][0]+dp[ch][1]);
        cnt_b%=mod; cnt_w%=mod;
    }
    dp[t][0]=cnt_b; dp[t][1]=cnt_w;
    return;
}
void solve()
{
  int n; cin>>n;
  for(int i=1;i<n;i++)
  {
      int a,b; cin>>a>>b;
      --a; --b;
      v[a].pb(b);
      v[b].pb(a);
  }
  dfs(0,-1);
  int ans=(dp[0][0]+dp[0][1])%mod;
  cout<<ans;
  return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--)solve();
    return 0;
}
