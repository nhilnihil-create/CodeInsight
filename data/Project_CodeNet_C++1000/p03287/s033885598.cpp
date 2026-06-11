#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n, m;
  cin >> n >> m;
  map<int,int> mp;
  ll tot = 0, ans = 0;
  ++mp[0];
  for(int i=0; i<n; ++i){
    int x;
    cin >> x;
    tot += x;
    tot %= m;
    ans += mp[tot];
    ++mp[tot];
  }
  cout << ans << endl;
}