#include <bits/stdc++.h>
#include <boost/integer/common_factor_rt.hpp>
using namespace std;
using ll=long long;
const int MOD=1000000007;

int main() {
  int n,m;
  cin >> n >> m;
  map<int,int> ma;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    vector<int> a(k);
    for(int j=0;j<k;j++){
      cin >> a.at(j);
      ma[a.at(j)]++;
    }
  }
  int ans=0;
  for (auto p : ma) {
  auto k = p.first;
  auto v = p.second;
  if(v==n)
  ans++;
}
cout << ans << endl;
}