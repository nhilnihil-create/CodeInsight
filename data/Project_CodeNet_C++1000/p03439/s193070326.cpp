#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N;
  cin >> N;
  cout << 0 << "\n";
  string lsex, rsex;
  cin >> lsex;
  rsex = lsex;
  if (lsex == "Vacant") {
    return 0;
  }
  ll l = 0, r = N;
  while (true) {
    ll m = (l + r) / 2;
    cout << m << "\n" << flush;
    string msex;
    cin >> msex;
    if (msex == "Vacant") {
      break;
    }
    if ((m - l) % 2 == 0) {
      if (msex != lsex) {
        r = m;
        rsex = msex;
      }
      else {
        l = m;
        lsex = msex;
      }
    }
    else {
      if (msex == lsex) {
        r = m;
        rsex = msex;
      }
      else {
        l = m;
        lsex = msex;
      }
    }
  }
}
