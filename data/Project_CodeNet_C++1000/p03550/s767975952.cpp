#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, z, w;
  cin >> n >> z >> w;
  
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  
  if(n == 1) cout << abs(a.at(0) - w) << '\n';
  else cout << max(abs(a.at(n - 1) - a.at(n - 2)), abs(a.at(n - 1) - w)) << '\n';
}