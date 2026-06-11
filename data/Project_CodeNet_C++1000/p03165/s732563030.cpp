
// Problem : F - LCS
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_f
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
#define FAST {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define rep(n) for(int i=0;i<(n);i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define INF (long long) 1e18
#define MOD 1000000007
#define MAX 200005;
string s,t;
int dp[3001][3001];
void solve(){
      cin>>s>>t;
      int n = s.length(),m = t.length();
      for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                  if(s[i]==t[j]){
                        dp[i+1][j+1] = dp[i][j] +1;
                  } else dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }
      }
      string ans;
      int i = n,j = m;
      while(i!=0&&j!=0){
            if(dp[i][j]==dp[i-1][j]) i--;
            else if(dp[i][j]==dp[i][j-1]) j--;
            else {
                  i--;j--;
                  ans.pb(s[i]);
            }
      }
      reverse(all(ans));
      cout<<ans<<endl;
}

int32_t main(){
      FAST
      int t=1;
      //cin>>t;
      while(t--)
            solve();
      return 0;
}


