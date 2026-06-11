#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define rep1(i,n) for (int i=1; i<=(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define fst first
#define scd second
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  int ans = 0;
  rep(i,n) {
    cin >> a[i];
    ans+=a[i];
  }
  ans -= n;
  cout << ans << endl;
  return 0;
}