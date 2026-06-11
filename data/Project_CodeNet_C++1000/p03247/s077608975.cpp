#include "bits/stdc++.h"

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair



int main() {
  int n;
  cin >> n;
  vl x(n), y(n);
  bool gu = false, ki = false;
  rep (i, n) {
    cin >> x[i] >> y[i];
    if ((x[i] + y[i]) % 2 == 0) {
      gu = true;
    }
    else {
      ki = true;
    }
  }
  if (gu && ki) {
    cout << -1 << endl;
    return 0;
  }
  int m = 40;
  vl d(m);
  if (gu) {
    d[m - 1] = 1;
    d[m - 2] = 1;
    rrep1 (i, m - 2) {
      d[i - 1] = d[i] * 2;
    }
  }
  else {
    d[m - 1] = 1;
    rrep1 (i, m - 1) {
      d[i - 1]  = d[i] * 2;
    }
  }
  cout << m << endl;
  rep (i, m) {
    cout << d[i] << " ";
  }
  cout << endl;
  rep (j, n) {
    ll u = x[j] + y[j], v = x[j] - y[j];
    ll now_x = 0, now_y = 0;
    string w;
    rep (i, m) {
      if (now_x <= u && now_y <= v) {
        w.push_back('R');
        now_x += d[i];
        now_y += d[i];
      }
      else if (now_x <= u && now_y > v) {
        w.push_back('U');
        now_x += d[i];
        now_y -= d[i];
      }
      else if (now_x > u && now_y > v) {
        w.push_back('L');
        now_x -= d[i];
        now_y -= d[i];
      }
      else {
        w.push_back('D');
        now_x -= d[i];
        now_y += d[i];
      }
    }
    cout << w << endl;
  }
}
