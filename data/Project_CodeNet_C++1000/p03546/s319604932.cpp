#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <tuple>
#include <bitset>
#include <random>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

 
int main() {
  int h,w;
  cin>>h>>w;
  vector<vector<int>> c(10,vector<int>(10)), a(h,vector<int>(w));
  REP(i,10){
    REP(j,10){
      cin>>c[i][j];
    }
  }

  REP(i,h){
    REP(j,w){
      cin>>a[i][j];
    }
  }

  vector<int> cost(10,1001);/*iから1に書き換えるコスト*/
  cost[1]=0;
  REP(v,10){
    REP(i,10){
      REP(j,10){
        cost[i]=min(cost[i], cost[j]+c[i][j]);
      }
    }
  }

  int ans=0;
  REP(i,h){
    REP(j,w){
      if(a[i][j]!=-1){
        ans+=cost[a[i][j]];
      }
    }
  }
     
  cout<<ans<<endl;
  return 0;
}