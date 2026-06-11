#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> x(m);
  rep(snip_i, m) cin >> x.at(snip_i);
  if(n >= m){
    cout << 0 << endl;
    return 0;
  }
  sort(x.begin(), x.end());
  vector<int> diff(m-1);
  ll sum = 0;
  rep2(i, 1, m){
    diff.at(i-1) = x.at(i) - x.at(i-1);
    sum += diff.at(i-1);
  }
  sort(diff.rbegin(), diff.rend());
  rep(i, n-1){
    sum -= diff.at(i);
  }
  cout << sum << endl;
  return 0;
}