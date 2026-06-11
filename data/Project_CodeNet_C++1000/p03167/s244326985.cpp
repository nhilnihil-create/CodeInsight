
// Problem : H - Grid 1
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_h
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
#define FAST {ios_base::sync_with_stdio(false);cin.tie(NULL);}
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define rep(n) for(int i=0;i<(n);i++)
#define rrep(n) for(int i=(n)-1;i>=0;i--)
#define mem(a,b) memset((a),(b),sizeof (a))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define INF (long long) 1e18
#define MOD 1000000007
int dp[1005][1005];
int32_t main(){
      int n,m;
      cin>>n>>m;
      bool arr[1005][1005];
      for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                  char ch;
                  cin>>ch;
                  if(ch == '#') arr[i][j] = 0;
                  else arr[i][j] = 1;
            }
      }
      for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                  if(i==1 && j==1) dp[i][j] = 1;
                  else if(arr[i][j] == 1){
                        dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
                  }else {
                        dp[i][j] = 0;
                  }
            }
      }
      cout<<dp[n][m]<<endl;
      return 0;
}


