#include <bits/stdc++.h>
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#define invrep(i,n) for(int64_t i=n-1;i >= 0;i--)
#define _GLIBCXX_DEBUG
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> conn(n);
  vector<int64_t> c(n);
  rep(i,n-1){
    int s,t;
    cin >> s >> t;
    conn[s-1].push_back(t-1);
    conn[t-1].push_back(s-1);
  }
  rep(i,n){
    cin >> c[i];
  }
  sort(c.begin(),c.end());
  reverse(c.begin(),c.end());
  vector<int> res(n);
  vector<bool> isused(n);
  queue<int> que;
  que.push(0);
  int h=0;
  while(!que.empty()){
    int x = que.front();
    res[x] = c[h];
    isused[x] = true;
    h++;
    rep(i,conn[x].size()){
      if(!isused[conn[x][i]]){
        que.push(conn[x][i]);
      }
    }
    que.pop();
  }
  cout << accumulate(c.begin(),c.end(),0L)-c[0] << endl;
  rep(i,n){
    cout << res[i] << " ";
  }
    
  
}