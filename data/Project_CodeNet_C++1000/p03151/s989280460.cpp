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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b(n);
  rep(i, n) cin >> b.at(i);
  vector<int> pl;
  int ans = 0;
  ll mi = 0;
  rep(i, n){
    if(a.at(i) > b.at(i)) pl.push_back(a.at(i)-b.at(i));
    else{
      mi += b.at(i)-a.at(i);
      if(b.at(i)-a.at(i) != 0) ans++;
    }
  }
  sort(ALL(pl), greater<int>());

  rep(i, pl.size()){
    if(mi <= 0) break;
    ans++;
    mi -= pl.at(i);
  }
  if(mi <= 0) cout << ans << endl;
  else cout << -1 << endl;
  return 0;
}