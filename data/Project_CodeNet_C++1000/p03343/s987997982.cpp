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

  int n, k, q; cin >> n >> k >> q;
  vi a(n);
  REP(i, n) cin >> a[i];

  ll su = LINF;
  REP(i, n) {
    ll now = a[i];
    multiset<ll> st;
    multiset<ll> koho;
    REP(j, n) {
      if(a[j] < now) {
        //cout << j << ":" << SZ(st) << " ";
        if(SZ(st) >= k) {
          int cnt = 0;
          for(auto &e: st) {
            cnt++;
            if(cnt > SZ(st) - k + 1) break;
            koho.insert(e);
          }
        }
        st.clear();
      } else {
        st.insert(a[j]);
      }
    }
    //cout << n << ":" << SZ(st) << " ";
    if(SZ(st) >= k) {
      int cnt = 0;
      for(auto &e: st) {
        cnt++;
        if(cnt > SZ(st) - k + 1) break;
        koho.insert(e);
      }
    }

    int cnt = 0;
    ll nowans = LINF;
    //cout << endl;
    //cout << now << ": ";
    for(auto &e: koho) {
      //cout << e << " ";
      cnt++;
      if(cnt == q) {
        nowans = e - now;
        break;
      }
    }
    //cout << endl;

    if(cnt >= q) chmin(su, nowans);
  }
  cout << su << endl;
}






















