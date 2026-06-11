#define LOCAL
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
static const int INTINF = (INT_MAX >> 1); // 10^9 + 10^7
static const ll LLINF = (LLONG_MAX >> 1);
static const int MAX = 1e5+1;
static const ll MOD = 1e9+7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <size_t N> string to_string(bitset<N> bs) {
  string res;
  for (size_t i = 0; i < N; ++i) res += '0' + bs[i];
  return res;
}
string to_string(vector<bool> v) {
  string res = "{";
  for (bool e : v) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p);
template <class C> string to_string(C c) {
  string res = "{";
  for (auto e : c) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug() { cerr << '\n'; }
template <class Head, class... Tail> void debug(Head head, Tail... tail) {
  cerr << '\t' << to_string(head), debug(tail...);
}
#ifdef LOCAL
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

struct point{
  ll x, y, idx;
};

int main(int argc, const char * argv[]) {
  std::cout << std::fixed << std::setprecision(15);

  ll N, K; cin >> N >> K;
  vector<point> v(N);
  rep(i, N){
    ll x, y; cin >> x >> y;
    v[i] = {x, y, i};
  }

  ll ans = LLINF;
  rep(i, N){
    point lp = v[i];
    rep(j, N){
      if(lp.idx == v[j].idx) continue;
      if(v[j].x < lp.x) continue;
      point rp = v[j];
      rep(k, N){
        if(v[k].y < max(lp.y, rp.y)) continue;
        point tp = v[k];
        rep(t, N){
          if(v[t].y > min(lp.y, rp.y)) continue;
          point dp = v[t];
          int cnt = 0;
          rep(s, N){
            if(v[s].x < min(lp.x, rp.x) || max(lp.x, rp.x) < v[s].x) continue;
            if(v[s].y < min(tp.y, dp.y) || max(tp.y, dp.y) < v[s].y) continue;
            cnt++;
          }
          if(cnt >= K){
            ll area = abs(max(lp.x, rp.x) - min(lp.x, rp.x)) * abs(max(tp.y, dp.y) - min(tp.y, dp.y));
            chmin(ans, area);
          }
        }
      }
    }
  }

  cout << ans << endl;
}  
