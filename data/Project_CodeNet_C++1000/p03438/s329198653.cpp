#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
const ll mod = 1000000007;

const string yes = "Yes";
const string no = "No";

int main()
{
  int n; cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  if (a == b) {
    cout << yes << endl;
    return 0;
  }

  ll cnt = 0;
  rep(i, n) {
    if (b[i] >= a[i]) {
      cnt += (b[i]-a[i])/2;
    } else {
      cnt -= a[i]-b[i];
    }
  }

  if (cnt < 0) cout << no << endl;
  else cout << yes << endl;

  return 0;
}
