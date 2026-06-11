#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  if (n == 1 && m == 1)
    cout << "1\n";
  else if (n == 1) 
    cout << max(0ll, m - 2) << '\n';
  else if (m == 1)
    cout << max(0ll, n - 2) << '\n';
  else {
    long long down = n * m - (2 * n + 2 * (m - 2));
    cout << down << '\n';
  }
  // borders have    
  return 0;
}