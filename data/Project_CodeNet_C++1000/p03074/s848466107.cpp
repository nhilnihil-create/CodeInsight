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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<pair<bool, int>> vp;
  int co = 1;
  rep2(i, 1, s.size()){
    if(s.at(i) != s.at(i-1)){
      vp.push_back({s.at(i-1) == '1', co});
      co = 1;
    }else co++;
  }
  vp.push_back({s.back() == '1', co});

  int ans = 0, ck = 0, stindex = -1;
  rep(i, vp.size()){
    if(vp.at(i).first == false){
      if(ck == k){
        stindex = i;
        break;
      }
      ck++;
    }
    ans += vp.at(i).second;
  }

  int tmp = ans;
  int reindex = 0;
  while(stindex < vp.size()){
    // cerr << reindex << " " << stindex << " " << tmp <<endl;
    while(vp.at(reindex).first != false){
      tmp -= vp.at(reindex).second;
      reindex++;
    }
    tmp -= vp.at(reindex).second;
    reindex++;
    int bf = stindex;
    while(bf == stindex || stindex != vp.size() && vp.at(stindex).first != false){
      tmp += vp.at(stindex).second;
      stindex++;
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}