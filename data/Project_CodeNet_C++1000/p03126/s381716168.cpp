#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const float pi = 3.1415926535;
unsigned GetDigit(unsigned num){
    return to_string(num).length();
}

int main() {
  int n,m,ans=0;
  cin >> n >> m;
  vector<int> table(m+1);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
      int x; cin >> x;
      table.at(x)++;
    }
  }
  for (int i = 0; i < m+1; i++) {
    if (table.at(i) == n) ans++;
  }
  cout << ans << endl;
}