#include <bits/stdc++.h>
using namespace std;
using in6 = int64_t;
using ind = double;
using vi = vector<in6>;
using vii = vector<vi>;
using vs = vector<string>;
using pii = pair<in6,in6>;
using psi = pair<string,in6>;
using vpi = vector<pii>;
using vps = vector<psi>;
#define rep(i, n) for (in6 i = 0; i < (in6)(n); i++)
#define repa(i,a,n) for(in6 i = a; i < (in6)(n); i++)
#define repdown(i,n) for(in6 i = n; i > 0; i--)
#define kyun ios::sync_with_stdio(false)
#define hinata cout << "\n"
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define inf 2147483647
#define dset(n) cout << fixed << setprecision(n)

void yes() {
  cout << "Yes";
}

void no() {
  cout << "No";
}

int main() {
  kyun;
  vi data(5);
  rep(i,5) cin >> data[i];
  vi amari(5);
  rep(i,5) amari[i] = data[i] % 10;
  in6 ans = 0;
  rep(i,5) {
    if(amari[i] != 0) amari[i] = 10-amari[i];
  }
  sort(all(amari));
  rep(i,5) {
    ans += data[i];
    if(i != 4) ans += amari[i];
  }
  cout << ans;
  hinata;
}