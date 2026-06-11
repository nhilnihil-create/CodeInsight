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
  int n;
  cin >> n;
  vector<int> idx(n);
  rep(i, n){
    int in;
    cin >> in;
    idx.at(in-1) = i;
  }
  int ans = 0, add = 0, bf = 0;
  rep(i, n){
    if(i == 0){
      add++;
    }else{
      if(bf > idx.at(i)){
        ans = max(ans, add);
        add = 1;
      }else{
        add++;
      }
    }
    bf = idx.at(i);
    // cerr << ans << " " << add << endl;
  }
  ans = max(ans, add);
  cout << n-ans << endl;
  return 0;
}