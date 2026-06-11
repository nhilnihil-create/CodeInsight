#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  string a, b;
  cin >> a >> b;

  if (a[0] == b[2] && a[1] == b[1] && a[2] == b[0]) cout << "YES" << "\n";
  else cout << "NO" << "\n";
}
