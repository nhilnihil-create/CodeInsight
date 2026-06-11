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

int32_t main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
   //   freopen("q.gir","r",stdin);
   //   freopen("q.cik","w",stdout);
      int n;
      cin>>n;
      string s;
      cin>>s;
      vector<vector<int>>dp(n+1,vector<int>(n+1,0));
      vector<vector<int>>pre(n+1,vector<int>(n+1,0));
      dp[1][1]=1;
      pre[1]=vector<int>(n+1,1);pre[1][0]=0;
      for(int i=2;i<=n;i++){
            if(s[i-2]=='<'){
                  for(int j=1;j<=i;j++){
                        dp[i][j]=(pre[i-1][i-1]-pre[i-1][j-1]+modulo)%modulo;
                  }
            }
            else{
                  for(int j=1;j<=i;j++){
                        dp[i][j]=pre[i-1][j-1];
                  }
            }
            for(int j=1;j<=i;j++){
                  pre[i][j]=(pre[i][j-1]+dp[i][j])%modulo;
            }
      }
      cout<<pre[n][n];
}
