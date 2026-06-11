#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  long long n, m;
  cin >> n >> m;

  long long res; 
  if (n == 1 && m == 1) res = 1;
  else if (n == 1 && m > 1) res = m-2;
  else if (m == 1 && n > 1) res = n-2;
  else res = (n-2)*(m-2);
  cout << res << endl;

  return 0;
}

