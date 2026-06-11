#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}


int main() {
  ll x, y, z, K; cin >> x >> y >> z >> K;
  Vll a(x), b(y), c(z);
  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  rep(i, z) cin >> c[i];
  sort(all(a), greater<ll>());
  sort(all(b), greater<ll>());
  sort(all(c), greater<ll>());

  priority_queue<tuple<ll, int, int, int>> pq;
  pq.push(make_tuple(a[0]+b[0]+c[0], 0, 0, 0));

  set<int> done;
  done.insert(0);

  rep(_, K) {
    ll f; int i, j, k;
    tie(f, i, j, k) = pq.top(); pq.pop();
    cout << f << endl;

    int next;

    next = (i+1)*y*z + j*z + k;
    if (done.count(next) == 0 && i+1 < x) {
      pq.push(make_tuple(a[i+1]+b[j]+c[k], i+1, j, k));
      done.insert(next);
    }
    next = i*y*z + (j+1)*z + k;
    if (done.count(next) == 0 && j+1 < y) {
      pq.push(make_tuple(a[i]+b[j+1]+c[k], i, j+1, k));
      done.insert(next);
    }
    next = i*y*z + j*z + k+1;
    if (done.count(next) == 0 && k+1 < z) {
      pq.push(make_tuple(a[i]+b[j]+c[k+1], i, j, k+1));
      done.insert(next);
    }
  }
  return 0;
}
