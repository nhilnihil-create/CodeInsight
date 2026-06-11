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
  ll mi = 0, mc = 0, adsum = 0;
  vector<int> add;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b(n);
  rep(i, n) cin >> b.at(i);
  rep(i, n){
    if(a.at(i) > b.at(i)){
      adsum += a.at(i)-b.at(i);
      add.push_back(a.at(i)-b.at(i));
    }
    if(a.at(i) < b.at(i)){
      mi += b.at(i)-a.at(i);
      mc++;
    }
  }
  if(adsum < mi){
    cout << -1 << endl;
    return 0;
  }

  sort(add.rbegin(), add.rend());
  int ans = mc;
  // cerr << ans << endl;
  for(int i : add){
    if(mi <= 0) break;
    ans++;
    mi -= i;
  }
  cout << ans << endl;
  return 0;
}