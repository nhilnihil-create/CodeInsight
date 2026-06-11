#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N;
  cin>>N;
  vector<vector<int>> graph(N);
  for(int i = 0; i < N-1; i++) {
    int x,y;
    cin>>x>>y;
    graph[x-1].push_back(y-1);
    graph[y-1].push_back(x-1);
  }
  priority_queue<ll> point;
  ll cnt = 0LL;
  for(int i = 0; i < N; i++) {
    ll x;
    cin>>x;
    point.push(x);
    cnt+=x;
  }
  queue<int> dfs;
  vector<bool> seen(N,false);
  vector<ll> ans(N);
  dfs.push(0);
  seen[0]=true;
  ans[0]=point.top();
  point.pop();
  cnt-=ans[0];
  while(!dfs.empty()){
    int x = dfs.front();
    dfs.pop();
    for(auto nx:graph[x]){
      if(seen[nx]) continue;
      seen[nx]=true;
      dfs.push(nx);
      ans[nx]=point.top();
      point.pop();
    }
  }
  cout<<cnt<<endl;
  for(auto x:ans) cout<<x<<endl;
}