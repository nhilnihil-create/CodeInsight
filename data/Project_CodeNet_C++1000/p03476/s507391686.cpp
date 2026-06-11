#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
const ll mod = 1e9+7;
const ll INF = 1e18;
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)

bool isPrime(int x) {
  int i;
  if(x < 2)return 0;
  else if(x == 2) return 1;
  if(x%2 == 0) return 0;
  for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
  return 1;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  vector<ll> a(100010);
  for (ll i = 1; i < 100001; ++i) {
    if (i%2 == 1) {
      if (isPrime(i) && isPrime((i+1)/2)) {
        a[i] = a[i-1]+1;
      }
      else {
        a[i] = a[i-1];
      }
    }
    else {
      a[i] = a[i-1];
    }
  }
  ll q;
  cin >> q;
  rep(i,q) {
    ll l, r;
    cin >> l >> r;
    cout << a[r]-a[l-1] << '\n';
  }

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}