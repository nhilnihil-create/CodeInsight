#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = 1; i <= (int)(n); i++)
#define drep(i, n) for(int i = (n)-1; i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()
#define dup(x,y) (((x)+(y)-1)/(y))
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// Mod int
const int mod = 1000000007;
// const int mod = 998244353;
struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  // mint(ll x):x(x){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}
//



int main() {
  int h, w;
  cin >> h >> w;
  vvi a(h, vi(w));
  rep(i, h) rep(j, w) cin >> a[i][j];
  vvi ans;
  auto update = [&](int i, int j, int k, int l) {
    vi now = {i, j, k, l};
    ans.push_back(now);
  };

  rep(i, h) rep(j, w-1) {
    if (a[i][j]%2) {
      --a[i][j];
      ++a[i][j+1];
      update(i, j, i, j+1);
    }
  }
  rep(i, h-1) {
    if (a[i][w-1]%2) {
      --a[i][w-1];
      ++a[i+1][w-1];
      update(i, w-1, i+1, w-1);
    }
  }

  int m = ans.size();
  cout << m << endl;
  rep(i, m) {
    rep(j, 4) printf("%d%c", ans[i][j]+1, j==3 ? '\n':' ');
  }
}