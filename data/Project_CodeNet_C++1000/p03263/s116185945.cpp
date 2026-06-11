#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int H,W;
  cin>>H>>W;
  vector<vector<int>> vv(H);
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      int x;
      cin>>x;
      if(x%2==1) vv[i].push_back(j);
    }
  }
  vector<vector<int>> v;
  vector<vector<int>> memo;
  rep(i,H){
    if((int)vv[i].size()%2==1) memo.push_back({i,vv[i][vv[i].size()-1]});
    for(int j = 0; j < (int)vv[i].size()-1;j+=2){
      for(int k = vv[i][j];k<vv[i][j+1];k++){
        v.push_back({i,k,i,k+1});
      }
    }
  }
  for(auto x:memo){
    for(int i = x[1];i < W-1;i++){
      v.push_back({x[0],i,x[0],i+1});
    }
  }
  for(int i = 0; i < (int)memo.size()-1; i+=2){
    for(int j = memo[i][0];j < memo[i+1][0]; j++){
      v.push_back({j,W-1,j+1,W-1});
    }
  }
  cout<<v.size()<<endl;
  for(auto x:v){
    cout<<x[0]+1<<" "<<x[1]+1<<" "<<x[2]+1<<" "<<x[3]+1<<endl;
  }
}
      