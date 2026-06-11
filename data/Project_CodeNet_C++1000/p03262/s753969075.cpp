#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, x; cin >> n >> x;
  vector< int > v;
  v.push_back(x);
  int y = 0;
  for(int i = 0; i < n; ++i){
    cin >> y;
    v.push_back(y);
  }
  sort(v.begin(),v.end());
  int z = v[1] - v[0];
  int ans = z;
  for(int i = 2; i < (int)v.size(); ++i){
     ans = __gcd(ans,v[i] - v[i - 1]);
  }
  cout << ans << '\n';
}