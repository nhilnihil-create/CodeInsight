#include<bits/stdc++.h>
#define ll long long
using namespace std;
signed main() {
  int n, d;
  set<int> se;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> d;
    se.insert(d);
  }
  cout << se.size() << "\n";
  return (0);
}