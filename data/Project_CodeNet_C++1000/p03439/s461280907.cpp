#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> v;
string s;

void solve();

int main() {
  cin >> n;
  solve();
  return 0;
}

void solve() {
  long long l = 0, r = n - 1;
  bool gend = 0;
  v.assign(n, 0);
  cout << 0 << endl;
  cin >> s;
  gend = s == "Male";
  while(s != "Vacant") {
    long long now = (l + r) / 2;
    if(r - l == 1) now = r;
    bool nowgend = 0;
    cout << now << endl;
    cin >> s;
    nowgend = s == "Male";
    if((nowgend ^ (now - l) % 2) == gend) {
      l = now;
      gend = nowgend;
    }
    else
      r = now;
  }
}
