#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n, m, x;
  cin >> n >> m >> x;

  int a = 0, b = 0;
  for (int i = 0; i < m; ++i) {
    int y; cin >> y;

    if (y < x) a++;
    else b++;
  }

  cout << min(a, b) << "\n";
}
