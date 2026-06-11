#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,M;
  cin>>N>>M;
  vector<priority_queue<int>> v(N-1);
  rep(i,M){
    int x,y;
    cin>>x>>y;
    v[y-2].push(x-1);
  }
  int k = -1;
  int ans=0;
  rep(i,N-1){
    if(v[i].size()==0)continue;
    if(v[i].top()>k){
      k=i;
      ans++;
    }
  }
  cout<<ans<<endl;
}