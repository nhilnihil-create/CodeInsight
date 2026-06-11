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
    // x %= mod;
    if (y == 0) return 1;
    // return ((y % 2 == 1 ? x : 1) * power(x * x, y / 2)) % mod;
    return ((y % 2 == 1 ? x : 1) * power(x * x, y / 2));
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
// vector < vector < int >  > v(MAXN);
// int visit[MAXN];
// int d[MAXN];
// int deg[MAXN];

// void dfs(int index, int parent){
//   visit[index] = 1;
//   for(int i = 0;i<v[parent].size();i++){
//     int node = v[parent][i];
//     if(visit[node]) continue;
//     else if (!binary_search(v[index].begin(),v[index].end(),node)){
//       visit[node] = 1;
//       dfs(node,index);
//     }
//   }
// }
void pre(){
}

void solve(){

  int n,k;
  cin>>n>>k;

  int a[n];
  for(int i = 0;i<n;i++) cin>>a[i];

  //dp[i][j] is the number of ways to distribute j candies to i people
  long long int dp[n+1][k+1];
  memset(dp,0,sizeof(dp));

  dp[0][0] = 1;
  for(int i = 1;i<=k;i++){
    dp[0][i] = 0;
  }
  for(int i = 1;i<=n;i++){
    dp[i][0] = 1;
  }
  for(int i = 1;i<=n;i++){
    long long int sum[k+1] = {0};
    //getting the prefix sum array
    for(int j = 1;j<=k;j++){
      sum[j] = sum[j-1] + dp[i-1][j];
    }
    // for(int i = 0;i<=n;i++){
    //   cout<<sum[i]<<' ';
    // }
    // cout<<endl;

    for(int j = 1;j<=k;j++){
      int lowest = j - min(a[i-1],j);
      int highest = j;
      dp[i][j] = sum[highest] - sum[lowest] + dp[i-1][lowest];
      dp[i][j] %= mod;
    }
  }
  // cout<<endl;
  // for(int i = 0;i<=n;i++){
  //   for(int j = 0;j<=k;j++){
  //     cout<<dp[i][j]<<' ';
  //   }
  //   cout<<endl;
  // }
  cout<<dp[n][k];
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
