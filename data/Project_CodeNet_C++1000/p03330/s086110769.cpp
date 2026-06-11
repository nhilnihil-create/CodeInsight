#include<bits/stdc++.h>
#define rep(i, n) for(int i=0;i<n;i++)
#define repb(i, a, b) for(int i=a;i<b;i++)

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

const int INF = 1<<30;

int main(){
  int n, C;cin>>n>>C;
  vector<vector<int>> color(3, vector<int>());
  vector<vector<int>> w(C, vector<int>(C));
  rep(i, C)rep(j, C)cin>>w[i][j];
  rep(i, n)rep(j, n){
    int c;cin>>c;
    color[(i+j)%3].push_back(--c);
  }
  vector<vector<int>> cost(3, vector<int>(C, 0));
  rep(i, 3){
  	rep(c, C){
      for(int j=0;j<(int)color[i].size();j++){
      	if(color[i][j]!=c)cost[i][c]+=w[color[i][j]][c];
      }
    }
  }
  int ans=INF;
  rep(i, C)rep(j, C)rep(k, C){
  	if(i==j || j==k || k==i)continue;
    ans=min(ans, cost[0][i]+cost[1][j]+cost[2][k]);
  }
  cout<<ans<<endl;
  return 0;
}

