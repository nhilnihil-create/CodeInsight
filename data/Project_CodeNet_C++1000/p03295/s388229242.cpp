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
  int n, m;
  cin >> n >> m;
  using pi = pair<int,int>;
  vector<pi> v(m);
  repr(i, m, 0) {
    pi p;
    cin >> p.second >> p.first;
    v[i] = p;
  }
  sorti(v);
  int cnt = 0;
  pi now = v[0];
  for (int i = 1; i < m; ++i) {
    pi next = v[i];
    if (now.first <= next.second) {
      cnt += 1;
      now = next;
    }
  }
  cout << cnt + 1 << endl;
}