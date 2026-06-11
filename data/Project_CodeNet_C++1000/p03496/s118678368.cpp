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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vt<int> a(n);
  rep(i, 0, n) cin >> a[i];

  int MAX = max_element(all(a)) - a.begin();
  int MIN = min_element(all(a)) - a.begin();
  if(MAX == MIN) return cout << 0 << endl, 0;

  cout << 2 * n - 1 << endl;
  if(abs(a[MAX]) > abs(a[MIN])) {
    rep(i, 0, n) {
      cout << MAX + 1 << " " << i + 1 << endl;
    }
    rep(i, 1, n) {
      cout << i << " " << i + 1 << endl;
    }
  }
  else {
    rep(i, 0, n) {
      cout << MIN + 1 << " " << i + 1 << endl;
    }
    for(int i = n - 1; i > 0; --i) {
      cout << i + 1 << " " << i << endl;
    }
  }
}