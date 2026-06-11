#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  unsigned long long x,y;
  cin >> x >> y;
  if (x % y == 0 || y == 1) {
    cout << -1 << endl;
    return 0;
  }

  unsigned long long maxNum = 1000000000000000000;

  for (unsigned long long i = 1; i * x <= maxNum; ++i) {
    if ((i * x) % y != 0) {
      cout << x << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}