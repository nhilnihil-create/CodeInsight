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
  int n, z, w;
  cin >> n >> z >> w;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  int a1 = abs(a.back() - w);
  int a2 = 0;
  if(n > 1) a2 = abs(a.at(a.size()-2) - a.back());
  int ans = max(a1, a2);
  cout << ans << endl;
  return 0;
}