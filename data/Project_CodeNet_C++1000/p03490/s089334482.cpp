#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define RREP(i, n) RFOR(i, n, 0)
#define MFOR(i, m) for(auto i=(m).begin();i!=(m).end();i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())

typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1 << 30;

template<typename T>
void printv(vector<T> const& s) {
  REP(i, SZ(s)) {
    cout << s[i] << " ";
  }
  cout << endl;
}

int main () {
  cin.tie(0);
  cout << setprecision(10);

  string s; cin >> s;
  int x, y; cin >> x >> y;
  int sx = 0;
  vi vx, vy;
  bool disx = true;
  bool init = true;

  REP(i, SZ(s)) {
    if(s[i] == 'T') {
      init = false;
      disx = !disx;
      if(disx) {
        vx.pb(0);
      } else {
        vy.pb(0);
      }
    } else {
      if(init) sx++;
      else if(disx) vx[SZ(vx)-1]++;
      else vy[SZ(vy)-1]++;
    }
  }

  x -= sx;

  if(SZ(vx)) {
    vector<map<int, bool>> mx(SZ(vx));
    mx[0][vx[0]] = true;
    mx[0][-vx[0]] = true;
    REP(i, SZ(vx)-1) {
      MFOR(j, mx[i]) {
        if(j->first+vx[i+1] <= 8000) mx[i+1][j->first+vx[i+1]] = true;
        if(j->first-vx[i+1] >= -8000) mx[i+1][j->first-vx[i+1]] = true;
      }
    }

  

    bool okx = false;

    MFOR(i, mx[SZ(vx)-1]) if(i->first == x) okx = true;
    if(!okx) {
      cout << "No" << endl;
      return 0;
    }
  } else if(x != 0) {
    cout << "No" << endl;
    return 0;
  }

  if(SZ(vy)) {
    vector<map<int, bool>> my(SZ(vy));
    my[0][vy[0]] = true;
    my[0][-vy[0]] = true;
    REP(i, SZ(vy)-1) {
      MFOR(j, my[i]) {
        if(j->first+vy[i+1] <= 8000) my[i+1][j->first+vy[i+1]] = true;
        if(j->first-vy[i+1] >= -8000) my[i+1][j->first-vy[i+1]] = true;
      }
    }

    bool oky = false;

    MFOR(i, my[SZ(vy)-1]) if(i->first == y) oky = true;
    if(!oky) {
      cout << "No" << endl;
      return 0;
    }
  } else if(y != 0) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
}
