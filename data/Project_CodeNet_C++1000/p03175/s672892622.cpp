#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;
const int MAX_V = 10000;
typedef pair<int, int>P;
#define MOD 1000000007
ll dp[100100][2];
bool visited[100100];
vector<vector<int>>G(100100);

void dfs(int from){
  visited[from]=true;
  for(auto t:G[from]){
    if(visited[t]){continue;}
    dfs(t);
    ll w=0ll,b=0ll;
    w=dp[t][0]+dp[t][1];
    b=dp[t][0];  
    dp[from][0]*=w;
    dp[from][1]*=b;
    dp[from][0]%=MOD;
    dp[from][1]%=MOD;
  }
  return;
}

int main() {
  int N;
  cin>>N;
  rep(i,N-1){
    int x,y;
    cin>>x>>y;
    x--;y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  ll ans=0ll;
  rep(i,100100){dp[i][0]=1ll;dp[i][1]=1ll;visited[i]=false;}
  dfs(0);
  ans+=dp[0][0]+dp[0][1];
  ans+=MOD;
  ans%=MOD;
  cout<<ans;
}