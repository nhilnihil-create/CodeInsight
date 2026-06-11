#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  int count = 0;
  int ans;
  for(int i=max(a, b); i<=max(a, b); i--) {
    if(a%i == 0 && b%i == 0) count++;
    if(count == k) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}