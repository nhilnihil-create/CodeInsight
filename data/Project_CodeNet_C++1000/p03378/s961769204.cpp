#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n, m, x;
  cin >> n >> m >> x;
  int a[m];
  int ans, d = 0, u = 0;
  map<int, int> mp;
  rep(i, m) {
    cin >> a[i];
    mp[a[i]]++;
  }
  for(int i = x - 1; i > 0; i--){
    d += mp[i];
  }
  for(int i = x + 1; i < n; i++){
    u += mp[i];
  }
  ans = min(d,u);
  cout << ans<< endl;
    
  return 0;
}