#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int a1, a2, a3;
  cin >> a1 >> a2 >> a3;

  int mx = max({a1, a2, a3});

  int mn = min({a1, a2, a3});
  
  cout << mx  - mn;

   return 0;
}