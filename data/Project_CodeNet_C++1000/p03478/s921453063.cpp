#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 1; i < (ll)(n); i++)
#define ll long long
using namespace std;


int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int count = 0;
  rep (i, n + 1) {
    int isom = 0;
    int now = i;
    while (now > 0) {
      isom += now % 10;
      now /= 10;
    }
    if (isom >= a && isom <= b) {
      count += i;
    }
  }
  cout << count << endl;
}

