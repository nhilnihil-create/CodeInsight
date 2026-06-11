#include <bits/stdc++.h>
using namespace std;

// #define int long long // intで書いたけど心配なときにlong longに変換する
struct Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

/* short */
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second
#define ALL(v) begin(v), end(v)
#define RALL(v) rbegin(v), rend(v)
#define X real()
#define Y imag()

/* REPmacro */
#define REPS(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define REP(i, n) REPS(i, 0, n)
#define RREP(i, n) REPS(i, 1, n + 1)
#define DEPS(i, a, n) for (ll i = (a); i >= (ll)(n); --i)
#define DEP(i, n) DEPS(i, n, 0)
#define EACH(i, n) for (auto&& i : n)

/* debug */
#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

/* alias */
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using plglg = pair<ll, ll>;
using tlglglg = tuple<ll, ll, ll>;
using D = double;
using P = complex<D>;
using vs = vector<string>;
template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

/* const */
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;
const D EPS = 1e-9;
const int dx[] = {0, 1, 0, -1, 1, -1, 1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

/* func */
inline bool inside(int y, int x, int H, int W) {return y >= 0 && x >= 0 && y < H && x < W;}
inline int in() {int x; cin >> x; return x;}
inline ll IN() {ll x; cin >> x; return x;}
inline vs split(const string& t, char c) {vs v; stringstream s(t); string b; while(getline(s, b, c)) v.eb(b); return v;}
template <typename T> inline bool chmin(T& a, const T& b) {if (a > b) a = b; return a > b;}
template <typename T> inline bool chmax(T& a, const T& b) {if (a < b) a = b; return a < b;}
template <typename T, typename S> inline void print(const pair<T, S>& p) {cout << p.first << " " << p.second << endl;}
template <typename T> inline void print(const T& x) {cout << x << endl;}
template <typename T, typename S> inline void print(const vector<pair<T, S>>& v) {for (auto&& p : v) print(p);}
template <typename T> inline void print(const vector<T>& v, string s = " ") {REP(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");}
inline void yesno(bool ok, string yes = "Yes", string no = "No") {cout << (ok?yes:no) << endl;}


class Radix {
private:
  const char* s;
  int a[128];
public:
  Radix(const char* s = "0123456789ABCDEF") : s(s) {
    int i;
    for(i = 0; s[i]; ++i)
      a[(int)s[i]] = i;
  }
  std::string to(long long p, int q) {
    int i;
    if(!p)
      return "0";
    char t[64] = { };
    for(i = 62; p; --i) {
      t[i] = s[p % q];
      p /= q;
    }
    return std::string(t + i + 1);
  }
  std::string to(const std::string& t, int p, int q) {
    return to(to(t, p), q);
  }
  long long to(const std::string& t, int p) {
    int i;
    long long sm = a[(int)t[0]];
    for(i = 1; i < (int)t.length(); ++i)
      sm = sm * p + a[(int)t[i]];
    return sm;
  }
};

signed main() {
    //my-code
    int n, a, b, c; cin >> n >> a >> b >> c;
    vi l(n); REP(i, n) cin >> l[i];

    int ptnmx = 1;
    REP(i, n) ptnmx *= 4;

    string ptnstr;
    int zpad;
    int acnt, bcnt, ccnt, alen, blen, clen;
    int ans = INF;
    int subans;
    REP(ptn, ptnmx) {
        Radix r;
        ptnstr = r.to(ptn, 4);
        zpad = n - ptnstr.length();
        acnt = 0; bcnt = 0; ccnt = 0; alen = 0; blen = 0; clen = 0;
        REPS(i, zpad, n) {
            if (ptnstr[i-zpad] == '1') {
                acnt++;
                alen += l[i];
            } else if (ptnstr[i-zpad] == '2') {
                bcnt++;
                blen += l[i];
            } else if (ptnstr[i-zpad] == '3') {
                ccnt++;
                clen += l[i];
            }
        }
        if (acnt*bcnt*ccnt == 0) continue;
        subans = 0;
        subans += 10 * ( acnt-1 + bcnt-1 + ccnt-1 );
        subans += abs(alen-a) + abs(blen-b) + abs(clen-c);
        chmin(ans, subans);
    }

    print(ans);

    return 0;
}

// https://github.com/kurokoji/.cpp-Template/wiki テンプレートについて
// http://www.creativ.xyz/dump-cpp-652 dump()について
// https://gist.github.com/rigibun/7905920 色々