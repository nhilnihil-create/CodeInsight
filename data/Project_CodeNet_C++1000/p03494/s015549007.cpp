#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


int main() {

  int N; cin >> N;
  ll a[N];
  rep(i,N) cin >> a[i];

  int ans = 0;
  while (true){
    bool b = true;
    rep(i,N) if (a[i]%2 != 0 ) b = false;
    if (!b) break;
    rep(i,N) a[i] /= 2;
    ans++;
  }
  cout << ans << endl;
	return 0;
}

