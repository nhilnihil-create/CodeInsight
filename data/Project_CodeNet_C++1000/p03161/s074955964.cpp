
// Problem : B - Frog 2
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_b
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


void solve(){
      int n,k;
      cin>>n>>k;
      int arr[n],dp[n];
      rep(n) cin>>arr[i];
      for(int i=0;i<n;i++){
            if(i==0) {dp[i] = 0;continue;}
            else dp[i] = INT_MAX;
            for(int j=i-1;j>=max((int)0,i-k);j--){
                  dp[i] = min(dp[i],dp[j] + abs(arr[i]-arr[j]));
            }
      }
      cout<<dp[n-1]<<endl;
}

int32_t main(){
      FAST
      int t=1;
      //cin>>t;
      while(t--)
            solve();
      return 0;
}


