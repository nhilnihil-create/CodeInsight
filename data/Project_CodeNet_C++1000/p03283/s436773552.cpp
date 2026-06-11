#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int memo[550][550];

int main() {
  int N,M,Q;
  cin>>N>>M>>Q;
  vector<vector<int>> c(N);
  rep(i,M){
    int x,y;
    cin>>x>>y;
    c[x-1].push_back(y-1);
    memo[x-1][y-1]++;
  }
  
  rep(i,N-1){
    for(int j = i; j < N-1; j++){
      memo[i][j+1]+=memo[i][j];
    }
  }
  rep(i,Q){
    int p,q;
    cin >>p>>q;
    p--;
    q--;
    int ans = 0;
    for(int j = p; j <= q; j++) {
      ans+=memo[j][q];
    }
    cout<<ans<<endl;
  }
}