#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int f(int x) {
  int s = 0;

  while (x) {
    s += x % 10;
    x /= 10;
  }

  return s;
}

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n; cin >> n;

  if (n % f(n) == 0) cout << "Yes" << "\n";
  else cout << "No" << "\n";
}
