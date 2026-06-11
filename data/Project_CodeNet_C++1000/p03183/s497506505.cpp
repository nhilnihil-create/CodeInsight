#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define INF 100000000000000000
#define modulo 1000000007
#define mod 998244353
#define int long long int
using namespace std;
struct Tower{
      int w,s,v;
      Tower(int a,int b,int c){
            w=a;s=b;v=c;
      }
      bool operator<(Tower& X){
            return s+w<X.s+X.w;
      }
};
vector<Tower>arr(1,Tower(-INF,-INF,0));
int32_t main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
   //   freopen("q.gir","r",stdin);
   //   freopen("q.cik","w",stdout);
      int n;
      cin>>n;
      for(int i=0;i<n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            arr.pb(Tower(a,b,c));
      }
      sort(all(arr));
      vector<vector<int>>dp(n+1,vector<int>(20004,-100));
      dp[0][0]=0;
      for(int i=1;i<=n;i++){
            int w=arr[i].w;
            int s=arr[i].s;
            int v=arr[i].v;
            for(int j=0;j<dp[i].size();j++)dp[i][j]=max(dp[i][j],dp[i-1][j]);
            for(int j=0;j<=s;j++){
                  dp[i][j+w]=max(dp[i][j+w],dp[i-1][j]+v);
            }
      }
      int ans=0;
      for(int i=0;i<dp[n].size();i++)ans=max(ans,dp[n][i]);
      cout<<ans;
}
