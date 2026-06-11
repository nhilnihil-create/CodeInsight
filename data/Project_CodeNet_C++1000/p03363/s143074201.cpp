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

ll comb(ll x) {
  ll res = x*(x-1)/2;
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<ll> d(n);
  rep(i, n) {
    ll a;
    cin >> a;
    if (i == 0) d[i] = a;
    else d[i] = d[i-1] + a;
  }
  sort(ALL(d));
  ll ans = 0;
  ll now = d[0];
  ll c = 1;
  if (d[0] == 0) ans++; 
  rrep(i, n-1) {
    if (d[i] == 0) ans++;
    if (d[i] == now) c++;
    else {
      ans += comb(c);
      now = d[i];
      c = 1;
    }
  }
  ans += comb(c);
  
  cout << ans << endl;
}