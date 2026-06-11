#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i=j;i<n;++i)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(),i.rend()
#define INF 1e9
const int mod = 1e9 + 7;

typedef long long i64;
typedef pair<int, int> pi;

template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;

i64 gcd(i64 n, i64 m) {return (m == 0? n : gcd(m, n % m));}
i64 lcm(i64 n, i64 m) {return (n / gcd(n, m) * m);}
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;

  rep(i, 0, t) {
    i64 a, b, c, d;
    cin >> a >> b >> c >> d;

    if(b > a) {
      cout << "No\n";
      continue;
    }
    else if(b > d) {
      cout << "No\n";
      continue;
    }

    i64 tmp = b - gcd(b, d) + a % gcd(b, d);
    if(tmp > c) cout << "No\n";
    else cout << "Yes\n";
  }
}
