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


int d,g;

vector<vector<int>> dp(11,vector<int>(1001,0));

 
int main() {
  cin>>d>>g;
  vector<int> p(d+1,0), c(d+1,0);
  for(int i=1;i<=d;i++){
    cin>>p.at(i)>>c.at(i);
  }

  REP(i,d){
    REP(n,1001){
      dp.at(i+1).at(n)=max(dp.at(i+1).at(n),dp.at(i).at(n));
      for(int k=1;k<p.at(i+1)&&k<=n;k++){
        dp.at(i+1).at(n)=max(dp.at(i+1).at(n),100*(i+1)*k+dp.at(i).at(n-k));
      }
      if(p[i+1]<=n){
        dp.at(i+1).at(n)=max(dp.at(i+1).at(n),100*(i+1)*p.at(i+1)+c.at(i+1)+dp.at(i).at(n-p.at(i+1)));

      }

    }
  }
  REP(n,1001){
    if(dp.at(d).at(n)>=g){
      cout<<n<<endl;
      return 0;
    }
  }
  return 0;
}