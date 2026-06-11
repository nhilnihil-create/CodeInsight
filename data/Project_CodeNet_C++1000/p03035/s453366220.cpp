#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i = 0; i < (ll)n; i++)
#define all(x) (x).begin(), (x).end()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end());
// map<int,int> mp;

int main() {
  int A, B;
  cin >> A >> B;
  if (A >= 13) {
    cout << B << endl;

  } else if (A >= 6) {
    cout << B / 2 << endl;

  } else {
    cout << 0 << endl;
  }
}