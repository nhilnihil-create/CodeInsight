#include <bits/stdc++.h>
using namespace std;

#define INF 100000000000000

int main() {


  int64_t n,k;
  cin>>n>>k;

  vector<int64_t> h(n+1);
  for(int i=1;i<=n;i++){
    cin>>h.at(i);
  }

  vector<int64_t> cost(n+1,INF);
  cost.at(1)=0;
  for(int i=2;i<=n;i++){
    int64_t cost_min = INF;
    for(int j=1;j<=k && i>=j;j++){
        cost_min = min(cost_min, cost.at(i-j)+abs(h.at(i)-h.at(i-j)));
    }
    cost.at(i)=cost_min;
  }
  cout<<cost.at(n)<<endl;


  return 0;
}
