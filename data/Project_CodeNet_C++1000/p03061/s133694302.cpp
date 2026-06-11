#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(int i=cc;i>=n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }

int main(){
  int n;
  cin >> n;
  vector<int>a(n), left(n+1), right(n+1);
  rep(i, 0, n)cin >> a[i];
  rep(i, 0, n)left[i+1]=GCD(left[i],a[i]);
  rrep(i, n-1, 0)right[i]=GCD(right[i+1],a[i]);
  int ans = 0;
  rep(i, 0, n){
      chmax(ans, GCD(left[i],right[i+1]));
  }
  cout << ans << endl;
}