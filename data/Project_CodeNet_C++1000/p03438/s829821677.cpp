#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<ll> a(n), b(n);
  ll count = 0;
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    count -= a.at(i);
  }
  for (int i = 0; i < n; i++) {
    cin >> b.at(i);
    count += b.at(i);
  }
  
  ll adda = 0, addb = 0;
  for (int i = 0; i < n; i++) {
    if (a.at(i) < b.at(i)) {
      if ((b.at(i) - a.at(i)) % 2 == 0) adda += (b.at(i) - a.at(i)) / 2;
      else {
        adda += (b.at(i) - a.at(i) + 1) / 2;
        addb++;
      }
    }
    else if (a.at(i) > b.at(i)) addb += a.at(i) - b.at(i);
  }
  
  if (adda <= count && addb <= count && (count - adda) * 2 == count - addb) cout << "Yes\n";
  else cout << "No\n";
}