#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a.at(i);
  sort(a.begin(),a.end());
  cout << a.at(n-1) - a.at(0) << endl;
 }
