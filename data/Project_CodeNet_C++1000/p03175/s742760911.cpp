#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <bits/stdc++.h>
#define lli long long int
#define mp make_pair
#define pb push_back
using namespace std;

const lli mod = 1e9 + 7;

lli power(lli x, lli y) {
    x %= mod;
    if (y == 0) return 1;
    return ((y % 2 == 1 ? x : 1) * power(x * x, y / 2)) % mod;
    // return ((y % 2 == 1 ? x : 1) * power(x * x, y / 2));
}

vector <long long int> primeNumbers;

void SieveOfEratosthenes(int n){
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++){ 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=n; p++){
      if (prime[p]){
        primeNumbers.push_back(p);
      }
    }        
}

#define MAXN 100005
vector < vector < int> > v(MAXN);
int d[MAXN];
int vis[MAXN];
long long int dp[MAXN][2];
//dp[i][0] is for black
//dp[i][1] is for white

void dfs(int vertex){
  vis[vertex] = 1;
  for(int i = 0;i<v[vertex].size();i++){
    int node = v[vertex][i];
    if(vis[node] == 1);
    else{
      // temp = false;
      vis[node] = 1;
      dfs(node);
      vis[node] = 0;
    }
  }
      // dp[vertex][0] += dp[node][1];
      // dp[vertex][0] %= mod;
      // dp[vertex][1] += dp[node][0] + dp[node][1];
      // dp[vertex][1] %= mod;

  for(int i = 0;i<v[vertex].size();i++){
    int node = v[vertex][i];
    if(vis[node] == 1);
    else{
      vis[node] = 1;
      dp[vertex][0] *= dp[node][1];
      dp[vertex][0] %= mod;
      dp[vertex][1] *= (dp[node][0] + dp[node][1])%mod;
      dp[vertex][1] %= mod;
    }
  }

}

void pre(){
}

void solve(){
  int n;
  cin>>n;
  for(int i = 0;i<n-1;i++){
    int x,y;
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for(int i = 0;i<=n;i++){
    dp[i][0] = 1;
    dp[i][1] = 1;
  }

  int root = 1;
  dfs(root);
  int ans = dp[root][0]%mod + dp[root][1]%mod;
  ans %= mod;
  

  // for(int i = 1;i<=n;i++){
  //   cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
  // }



  cout<<ans;



















}
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
  #endif
 
  int t;
  // cin>>t;
  // scanf("%d",&t);
  t = 1;
  pre();
  while(t--){
    // cout<<
    solve();
 
    if(t>0){
      cout<<endl;
      // printf("\n");
    } 
  }
 
 
  cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
 
  return 0;
}
