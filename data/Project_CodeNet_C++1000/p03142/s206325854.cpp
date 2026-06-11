#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> from(n, vector<int>());
  vector<vector<int>> to(n, vector<int>());
  rep(i, n+m-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    from.at(b).push_back(a);
    to.at(a).push_back(b);
  }
  vector<int> co(n, 0);
  vector<int> ans(n);
  int st = 0;
  rep(i, n){
    if(from.at(i).size() == 0){
      ans.at(i) = -1;
      st = i;
    }
  }
  queue<int> q;
  q.push(st);
  while(!q.empty()){
    int now = q.front(); q.pop();
    for(int nx : to.at(now)){
      if(from.at(nx).size() - 1 != co.at(nx)){
        co.at(nx)++;
      }else{
        q.push(nx);
        ans.at(nx) = now;
      }
    }
  }
  rep(i, n){
    cout << ans.at(i)+1 << endl;
  }
  return 0;
}