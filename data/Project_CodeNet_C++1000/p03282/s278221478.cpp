#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  string s;
  cin >> s;
  
  ll k;
  cin >> k;
  
  ll res = 1;
  
  for (ll i = 0; i < k && i < s.size(); ++i) {
    ll l = s.at(i)-'0';
    if (l != 1) {
      res = l;
      break;
    }
  }
  
  cout << res << endl;
  return 0;
}