#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<vector<ll>> x(n, vector<ll>(3));
  for (int i = 0; i < n; i++) {
    cin >> x.at(i).at(1) >> x.at(i).at(2);
    x.at(i).at(0) = x.at(i).at(1) + x.at(i).at(2);
  }
  
  sort(x.rbegin(), x.rend());
  
  ll taka = 0, aoki = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) taka += x.at(i).at(1);
    else aoki += x.at(i).at(2);
  }
  
  cout << taka - aoki << '\n';
}