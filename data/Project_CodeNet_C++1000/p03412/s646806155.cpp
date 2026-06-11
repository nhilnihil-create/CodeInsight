#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())
#define REP(i, n) for(int i=0;i<(n);++i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RREP(i, n) for(int i=(int)(n);i>=0;--i)
#define RFOR(i, a, b) for(int i=(int)(a);i>=(int)(b);--i)
#define ALL(a) (a).begin(),(a).end()
#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;

const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;

template <typename T1, typename T2>
bool chmax(T1 &a, const T2 &b) {
  if(a < b) {a = b; return true;}
  return false;
}

template <typename T1, typename T2>
bool chmin(T1 &a, const T2 &b) {
  if(a > b) {a = b; return true;}
  return false;
}

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  REP(i, SZ(v)) {
    if(i) os << " ";
    os << v[i];
  }
  return os;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n; cin >> n;
  vi a(n), b(n);
  REP(i, n) {
    cin >> a[i];
  }
  REP(i, n) {
    cin >> b[i];
  }

  int ans = 0;
  RREP(d, 29) {
    int h = 1 << (d+1);
    int l = 1 << d;

    REP(i, n) {
      a[i] %= h;
      b[i] %= h;
    }

    sort(ALL(b));

    ll num = 0;
    REP(i, n) {
      int add = 0;
      if(l - a[i] >= 0) {
        auto it1 = lower_bound(ALL(b), l - a[i]);
        auto it2= lower_bound(ALL(b), h - a[i]);
        int pos1 = distance(b.begin(), it1);
        int pos2 = distance(b.begin(), it2);

        add += pos2 - pos1;
      } else {
        auto it1 = lower_bound(ALL(b), h - a[i]);
        int pos1 = distance(b.begin(), it1);
        add += pos1;
        auto it3 = lower_bound(ALL(b), h);
        auto it2 = lower_bound(ALL(b), h + l - a[i]);
        int pos3 = distance(b.begin(), it3);
        int pos2 = distance(b.begin(), it2);
        add += pos3 - pos2;
      }
      num += add;
    }
    if(num & 1) ans += l;
  }
  cout << ans << endl;

}






