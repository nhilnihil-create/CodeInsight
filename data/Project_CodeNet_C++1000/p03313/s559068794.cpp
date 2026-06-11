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
  vll a(1<<n);
  REP(i, 1<<n) {
    cin >> a[i];
  }

  vector<ll> ma1(1<<n), ma2(1<<n, -1);
  REP(i, 1<<n) ma1[i] = a[i];

  int dp1[1<<n][n+1], dp2[1<<n][n+1];
  REP(i, 1<<n) {
    dp1[i][0] = a[i];
    dp2[i][0] = 0;
  }
  REP(j, n) {
    REP(i, 1<<n) {
      if(i & (1<<j)) {
        vector<int> v;
        v.push_back(dp1[i&(~(1<<j))][j]);
        v.push_back(dp2[i&(~(1<<j))][j]);
        v.push_back(dp1[i][j]);
        v.push_back(dp2[i][j]);
        sort(ALL(v));
        reverse(ALL(v));
        dp1[i][j+1] = v[0];
        dp2[i][j+1] = v[1];
      } else {
        dp1[i][j+1] = dp1[i][j];
        dp2[i][j+1] = dp2[i][j];
      }
    }
  }

  int ma = 0;
  FOR(i, 1, 1<<n) {
    chmax(ma, dp1[i][n] + dp2[i][n]);
    cout << ma << endl;
  }


}






















