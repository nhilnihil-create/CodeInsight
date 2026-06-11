#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  sort(rbegin(a), rend(a));
  int x = a[0] * 10 + a[1];
  int y = a[2];
  cout << x + y << '\n';  
  return 0;
}