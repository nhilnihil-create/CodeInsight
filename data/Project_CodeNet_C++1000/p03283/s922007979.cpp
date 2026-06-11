#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define sz(a) a.size()
#define pi 3.14159
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PF push_front //deque
#define mp make_pair
#define pq priority_queue
#define mod 1000000007
#define f first
#define s second
#define pii pair< int, int >
#define vi vector<int>
#define vpii vector<pii>
#define debug(v) for(auto i:v) cout<<i<<" ";
#define tc int t; cin >> t; while(t--)
using namespace std;
void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void  solve(){
  int n,m,Q,p,q,l,r;
  cin>>n>>m>>Q;
  vector<vector<int>> dp(n+1,vector<int>(n+1,0));
  rep(i,0,m){
    cin>>l>>r;
    dp[l][r]++;
  }
  rep(i,1,n+1) rep(j,1,n+1)dp[i][j]+=dp[i][j-1];
  rep(i,1,n+1) rep(j,1,n+1)dp[i][j]+=dp[i-1][j];
  rep(i,0,Q){
    cin>>p>>q;
    cout<<dp[q][q]+dp[p-1][p-1]-dp[p-1][q]-dp[q][p-1]<<endl;
  }
}
int main(){
    optimizeIO();
    solve();
}
