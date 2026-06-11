#include <bits/stdc++.h>
using namespace std;

// 無限大の値
const int64_t INF = 1000000000;


int main() {

  int64_t n;
  cin>>n;


  vector<int64_t> h(n);
  for(int i=0;i<n;i++){
    cin>>h.at(i);
  }

  vector<int64_t> cost(n,INF);
  cost.at(0)=0;

  for(int i=1;i<n;i++){
    int64_t cost1,cost2;
    cost1 = cost.at(i-1)+abs(h.at(i)-h.at(i-1));

    if(i>=2)
      cost2 = cost.at(i-2)+abs(h.at(i)-h.at(i-2));
    else
      cost2 = INF;

    cost.at(i) = min(cost1,cost2);
  }


  cout<<cost.at(n-1)<<endl;


  return 0;
}
