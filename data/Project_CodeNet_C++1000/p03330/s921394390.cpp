#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF=1<<30;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,C;
  cin>>N>>C;
  vector<vector<int>> col(C,vector<int>(C));
  vector<map<int,int>> grid(3);
  rep(i,C){
    rep(j,C){
      cin>>col[i][j];
    }
  }
  rep(i,N){
    rep(j,N) {
      int x;
      cin>>x;
      grid[(i+j)%3][x-1]++;
    }
  }
  vector<vector<int>> cha;
  rep(i,C){
    rep(j,C){
      rep(k,C){
        cha.push_back({i,j,k});
      }
    }
  }
  int ans=INF;
  for(auto x:cha){
    if(x[0]==x[1]||x[1]==x[2]||x[2]==x[0])continue;
    int t=0;
    rep(i,3){
      for(auto y:grid[i]){
        t+=col.at(y.first).at(x[i])*y.second;
      }
    }
    chmin(ans,t);
  }
  cout<<ans<<endl;
}
  