#include <bits/stdc++.h>
using namespace std;

#define rep(i,j,n) for(int i=j;i<n;++i)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(), i.rend()
#define INF 1e9
#define LINF 1e18
const int mod = 1e9 + 7;

typedef long long i64;
typedef pair<int, int> pi;

template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;

i64 gcd(i64 n, i64 m) {return (m == 0? n : gcd(m, n % m));}
i64 lcd(i64 n, i64 m) {return (n / gcd(n, m) * m);}
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, q;
string s;
vt<char> t, d;

bool fanc(int m, bool left) {
  rep(i, 0, q) {
    if(t[i] == s[m]) {
      if(d[i] == 'L') m--;
      else m++;
    }
  }

  if(left) return (m == 0);
  else return (m == n + 1);
}

int binary_search() {
  int left = 0, right = n + 1;
  {
    int ng = n + 1;
    while(abs(ng - left) > 1) {
      int mid = (left + ng) / 2;
      if(fanc(mid, true)) left = mid;
      else ng = mid;
    }
  }
  {
    int ng = left;
    while(abs(right - ng) > 1) {
      int mid = (right + ng) / 2;
      if(fanc(mid, false)) right = mid;
      else ng = mid;
    }
  }
  return n - (n + 1 - right) - left;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> q >> s;
  t.resize(q); d.resize(q);
  rep(i, 0, q) cin >> t[i] >> d[i];
  s = " " + s + " ";
  cout << binary_search() << endl;
}