#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define ALL(a) (a).begin(), (a).end()
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define rep(i, n) FOR(i, 0, n)
#define repi(i, n) FOR(i, 1, n + 1)
#define pp(v) cerr << #v "=" << (v) << endl;
#define ppa(v) cerr << "- " << #v << endl; rep(i,v.size()) cerr << #v << "[" << i << "] = " << v[i] << endl;
#define div_ceil(a,b) ((a) + ((b) - 1)) / (b)
#define UNIQUE(v) v.erase( unique(ALL(v)), v.end() );
#define INF 0x3f3f3f3f
#define LLINF 1000111000111000111LL
#define MOD 1000000007
#define TIME system("date +%M:%S.%N")
using Graph = vector<vector<int>>;
using ll = long long;
template<class T> T gcd(const T &a, const T &b) { return a < b ? gcd(b, a) : b ? gcd(b, a % b) : a; }
template<class T> T lcm(const T &a, const T &b) { return a / gcd(a, b) * b; }

int main() {
  string s;cin>>s;
  int n = s.size();
  int k;cin>>k;
  vector<string> a;
  rep(i,n) {
    int len = min(n-i,k);
    rep(j,len) {
      string t = s.substr(i,j+1);
      a.push_back(t);
    }
  }
  sort(ALL(a));
  UNIQUE(a);
  string ans = a[k-1];
  cout << ans << endl;
}
