#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

bool fc(vector<vector<int>> &gr, pair<int, int> p){
  vector<bool> vb(gr.size(), false);
  vb.at(0) = true;
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int now = q.front(); q.pop();
    for(auto i : gr.at(now)){
      if(make_pair(now,i) == p || make_pair(i, now) == p) continue;
      if(vb.at(i) == true) continue;
      vb.at(i) = true;
      q.push(i);
    }
  }
  rep(i, vb.size()){
    if(vb.at(i) == false) return true;
  }
  return false;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> gr(n, vector<int>());
  vector<pair<int, int>> vp(m);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    gr.at(a).push_back(b);
    gr.at(b).push_back(a);
    vp.at(i) = make_pair(a, b);
  }
  int ans = 0;
  rep(i, m){
    if(fc(gr, vp.at(i)) == true) ans++;
  }
  cout << ans << endl;
  return 0;
}