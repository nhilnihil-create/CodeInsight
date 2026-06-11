#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int a, b, k;
  cin >> a >> b >> k;

  vector<int> res;
  for (int i = a; i <= b; ++i) {
    if (i < a + k || i > b - k) res.push_back(i);
  }

  for (int x: res) cout << x << endl;
}
