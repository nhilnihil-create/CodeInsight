#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  vector<int> a(5);
  rep(i,5) cin >> a[i];
  int k; cin >> k;
  bool ans = true;
  rep(i,5) rep(j,5) {
    if (abs(a[i] - a[j]) > k) ans = false; 
    break;
  }
  cout << ((ans) ? "Yay!" : ":(") << endl;
}