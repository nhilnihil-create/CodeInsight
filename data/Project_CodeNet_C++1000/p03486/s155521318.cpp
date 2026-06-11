#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  string s, t;
  cin >> s >> t;

  sort(begin(s), end(s));
  sort(begin(t), end(t), greater<int>());

  if (s < t) cout << "Yes" << "\n";
  else cout << "No" << "\n";
}
