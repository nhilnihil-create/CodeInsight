#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  map<int, int> o, e;
  rep(i, n){
    int v;
    cin >> v;
    if(i % 2 == 0) e[v]++;
    else o[v]++;
  }

  pair<int, int> po(-1, -1), pos(-1, -1), pe(-1, -1), pes(-1, -1);
  int to = 0, te = 0;
  for(auto p : o){
    to += p.second;
    if(po.second < p.second){
      pos = po;
      po = p;
    }else if(pos.second < p.second){
      pos = p;
    }
  }
  for(auto p : e){
    te += p.second;
    if(pe.second < p.second){
      pes = pe;
      pe = p;
    }else if(pes.second < p.second){
      pes = p;
    }
  }
  int ans;
  if(po.first != pe.first){
    ans = to - po.second + te - pe.second;
  }else{
    int ans1 = 1001001001, ans2 = 1001001001;
    if(pos.first == -1 && pes.first == -1){
      ans1 = to - po.second + te;
    }else if(pos.first == -1){
      ans1 = to - po.second + te;
    }else if(pes.first == -1){
      ans1 = to + te - pe.second;
    }else{
      ans1 = to - po.second + te - pes.second;
      ans2 = to - pos.second + te - pe.second;
    }
    ans = min(ans1, ans2);
  }
  cout << ans << endl;
  return 0;
}