#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n, a, b;
  cin >> n >> a >> b;

  int res = min(a * n, b);
  cout << res << "\n";
}
