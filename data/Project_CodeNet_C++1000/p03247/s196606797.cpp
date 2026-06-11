#include <bits/stdc++.h>

#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int INF = pow(2,29);
const int MOD = 1000000007;

int main() {
  int N; cin >> N;
  ll X[N], Y[N]; rep(i,N) cin >> X[i] >> Y[i];

  ll a[N], b[N];
  ll oe = abs(X[0]+Y[0])%2;
  rep(i,N) {
    if (abs(X[i]+Y[i])%2==oe) {
      a[i] = X[i]-Y[i];
      b[i] = X[i]+Y[i];
    }
    else{ 
      cout << -1 << endl;
      return 0;
    }
  }

  vector<ll> len;
  for (ll i=31; i>=0; i--) len.push_back(pow(2,i));
  if (!oe) len.push_back(1);

  cout << len.size() << endl;
  for (auto x: len) cout << x << " "; cout << endl;
  rep(i,N) {
    for(auto x: len) {
      bool ap, bp;
      if (a[i]>0) { a[i] -= x; ap = true; }
      else { a[i] += x; ap = false; }
      if (b[i]>0) { b[i] -= x; bp = true; }
      else { b[i] += x; bp = false; }

      string result;
      if (ap) result = bp ? "R" : "D";
      else result = bp ? "U" : "L";
      cout << result;
    }
    cout << endl;
  }
  return 0;
}