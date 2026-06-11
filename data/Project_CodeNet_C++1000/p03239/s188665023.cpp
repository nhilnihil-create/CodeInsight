#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int n,TotalTime;
  cin>>n>>TotalTime;
  int MinCost=1009;
  rep(i,n){
    int c,t;
    cin>>c>>t;
    if(TotalTime>=t) MinCost=min(MinCost,c);
  }
  if(MinCost==1009) cout<<"TLE"<<endl;
  else cout<<MinCost<<endl;
}