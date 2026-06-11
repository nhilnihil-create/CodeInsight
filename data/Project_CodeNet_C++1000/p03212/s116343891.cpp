#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  string n;
  cin >> n;

  ll ans = 0;
  string k = "3";

  while (true) {
    if (stol(k) > stol(n)) break;

    if (k.find('3') != k.npos && k.find('5') != k.npos &&
        k.find('7') != k.npos) {
      ans++;
    }

    int l = k.length();
    for (int i = l - 1; i >= 0; i--) {
      if (k[i] == '3') {
        k[i] = '5';
        break;
      } else if (k[i] == '5') {
        k[i] = '7';
        break;
      } else {
        if (i == 0) {
          k = "";
          rep(j, l + 1) k += "3";
        }
        k[i] = '3';
      }
    }
  }
  cout << ans << endl;
}
