#define LOCAL
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rrep(i, n) for(int i=(n-1); i>=0; --i)
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

vector<ll> s, t;
vector<pair<ll, ll> > st;
ll A, B, Q;

ll calc(pair<ll, ll> p){
  if(p.second == 0){
    ll right = distance(t.begin(), upper_bound(ALL(t), p.first));
    ll left = right-1;
    return min(t[right] - p.first, p.first - t[left]);
  }
  else{
    ll right = distance(s.begin(), upper_bound(ALL(s), p.first));
    ll left = right-1;
    return min(s[right] - p.first, p.first - s[left]);
  }
}

int main(int argc, const char * argv[]) {
  std::cout << std::fixed << std::setprecision(15);

  cin >>A >> B >> Q;
  s.resize(A); t.resize(B);
  rep(i, A) cin >> s[i];
  rep(j, B) cin >> t[j];
  s.push_back(LLINF);
  s.push_back(-LLINF);
  t.push_back(LLINF);
  t.push_back(-LLINF);

  sort(ALL(s));
  sort(ALL(t));
  rep(i, Q){
    ll x; cin >> x;
    ll tr = distance(t.begin(), upper_bound(ALL(t), x));
    ll tl = tr - 1;
    ll t1 = t[tr] - x + calc({t[tr], 1});
    ll t2 = x - t[tl] + calc({t[tl], 1});
    if(t1 < 0) t1 =LLINF;
    if(t2 < 0) t2 =LLINF;
    // DEBUG(t[tr]);
    // DEBUG(t[tl]);
    // DEBUG(t1);
    // DEBUG(t2);

    ll sr = distance(s.begin(), upper_bound(ALL(s), x));
    ll sl = sr - 1;
    ll s1 = s[sr] - x + calc({s[sr], 0});
    ll s2 = x - s[sl] + calc({s[sl], 0});
    ll ans = LLINF;
    if(s1 < 0) s1 =LLINF;
    if(s2 < 0) s2 =LLINF;
    // DEBUG(s[sr]);
    // DEBUG(s[sl]);
    // DEBUG(s1);
    // DEBUG(s2);
    ans = min(min(t1, t2), min(s1, s2));
    cout << ans << endl;
  }
}  
