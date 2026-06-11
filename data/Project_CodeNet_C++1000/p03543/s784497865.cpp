#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n; cin >> n;

  vector<int> v;
  for (int i = 0; i < 4; ++i) {
    v.push_back(n % 10);
    n /= 10;
  }

  if (v[0] == v[1] && v[1] == v[2]) cout << "Yes" << "\n";
  else if (v[1] == v[2] && v[2] == v[3]) cout << "Yes" << "\n";
  else cout << "No" << "\n";
}
