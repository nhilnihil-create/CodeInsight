#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, k;
  cin >> n >> k;
  cout << ((n + k - 1) / k) - (n / k) << '\n';  
  return 0;
}