#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <deque>
#define MAX_N 100000
#define INF 1000000000000
typedef long long ll;
using namespace std;

int main(){
  ll cost[100000];
  ll K,tv,nv;
  deque<ll> V;
  cin>>K;

  for(int i=0;i<K;i++){
    cost[i]=INF;
  }
  cost[1]=0;
  V.push_back(1);

  while(!V.empty()){
    tv =V.front() ;
    V.pop_front();
    nv=(tv+1)%K;
    if(cost[nv]>cost[tv]+1){
      cost[nv]=cost[tv]+1;
      V.push_back(nv);
    }
    nv=(tv*10)%K;
    if(cost[nv]>cost[tv]){
      cost[nv]=cost[tv];
      V.push_front(nv);
    }
  }
  cout<<cost[0]+1<<endl;
  return 0;
}
