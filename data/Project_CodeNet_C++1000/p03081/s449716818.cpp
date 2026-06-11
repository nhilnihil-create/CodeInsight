#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N, Q; cin >> N >> Q;
  string s; cin >> s; s = "." + s + ".";
  char t[Q], d[Q]; rep(i,Q) cin >> t[i] >> d[i];
  ll result = N;

  ll l = 0, r = N+1;
  while (l!=r) {
    ll mid = (l+r+1)/2;
    ll pos = mid;
    rep(i,Q) {
      if (s[pos]==t[i]) {
        pos += d[i]=='L' ? -1 : 1;
      }
    }
    if (pos==0) l = mid;
    else r = mid - 1;
  }
  result -= l;

  l = 0; r = N+1;
  while (l!=r) {
    ll mid = (l+r)/2;
    ll pos = mid;
    rep(i,Q) {
      if (s[pos]==t[i]) {
        pos += d[i]=='L' ? -1 : 1;
      }
    }
    if (pos==N+1) r = mid;
    else l = mid + 1;
  }
  result -= (N+1)-l;

  cout << result << endl;
  return 0;
}