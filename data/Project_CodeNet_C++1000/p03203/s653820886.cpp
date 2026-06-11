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

  int h, w, n; cin >> w >> h >> n;
  vvi v(h);
  //vector<string> grid(h);
  /*
  REP(i, h) {
    REP(j, w) {
      grid[i].push_back('.');
    }
  }
  */

  REP(i, n) {
    int x, y; cin >> y >> x;
    x--; y--;
    //grid[x][y] = '#';
    v[x].push_back(y);
  }
  REP(i, h) {
    if(SZ(v[i]) != 0) sort(ALL(v[i]));
  }
  /*
  REP(i, h) {
    REP(j, w) {
      cout << grid[i][j];
    }
    cout << endl;
  }
  */


  if(n == 0) {
    cout << w << endl;
    return 0;
  }

  int pos = SZ(v[0]) == 0 || v[0][0] != 1;
  int prev = (SZ(v[0]) == 0 ? w : v[0][0]);
  set<int> cand;
  cand.insert(prev);
  FOR(i, 1, h) {
    int nxt = w;
    bool end = false;
    REP(j, SZ(v[i])) {
      if(v[i][j] == pos) {
        if (pos == prev - 1) {
          end = true;
          break;
        } else {
          pos++;
        }
      } else if(v[i][j] == pos + 1) {
        nxt = pos + 1;
        end = true;
        break;
      } else if(v[i][j] > pos) {
        nxt = v[i][j];
        break;
      }
    }
    //cout << i << ":" << pos << ":" << nxt << endl;
    cand.insert(nxt);
    if(end) {
      break;
    }
    prev = nxt;
    pos++;
  }

  cout << *(cand.begin()) << endl;

}





















