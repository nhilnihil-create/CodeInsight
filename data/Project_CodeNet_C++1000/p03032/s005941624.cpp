#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = 1; i <= (int)(n); i++)
#define drep(i, n) for(int i = (n)-1; i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;

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
  int n, k;
  cin >> n >> k;
  vi v(n);
  rep(i, n) cin >> v[i];
  int ans = -INF;
  if (k >= n) {
    sort(ALL(v));
    int sum = 0;
    rep(i, v.size()) sum += v[i];
    int cnt = min(k - n, n);
    rep(i, cnt) if (v[i] < 0) sum -= v[i];
    cout << sum << endl;
    return 0;
  }
  rep(i, k+1) {
    int res = k - i;
    rep(l, i+1) {
      vi x;
      int r = i - l;
      if (r < 0) continue;
      rep(nl, l) {
        x.push_back(v[nl]);
      }
      int t = 0;
      while (r) {
        x.push_back(v[n - 1 - t]);
        ++t;
        --r;
      }
      sort(ALL(x));
      int sum = 0;
      rep(j, x.size()) sum += x[j];
      int cnt = min(res, (int)x.size());
      rep(j, cnt){
        if (x[j] < 0) sum -= x[j];
      }
      ans = max(ans, sum);
    }
  }
  cout << ans << endl;
}