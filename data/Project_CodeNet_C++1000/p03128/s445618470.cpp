#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<utility>
#include<math.h>
#include<cstdlib>
#define rep(i, n) for(int i=0;i<n;i++)
#define repb(i, a, b) for(int i=a;i<b;i++)

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

const int INF = 1<<30;

int main(){
  int n, m;cin>>n>>m;
  int all_cost[] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
  vector<int> dp(n+1, -INF); // dp[i+1] := i本使って作る整数の最大桁数
  vector<P> cost(m);
  rep(i, m){
    int a;cin>>a;
    cost[i] = P(-a, all_cost[a-1]);
  }
  sort(cost.begin(), cost.end());
  dp[0] = 0;
  repb(i, 1, n+1){
    rep(j, m){
      if(i-cost[j].second<0)continue;
      dp[i] = max(dp[i], dp[i-cost[j].second]+1);
    }
  }
  while(n>0){
    rep(i, m){
      if(n-cost[i].second<0 || dp[n]-1!=dp[n-cost[i].second])continue;
      cout<<-cost[i].first;n -= cost[i].second;break;
    }
  }
  cout<<endl;
  // for(auto& e: dp)cout<<e<<" ";cout<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
