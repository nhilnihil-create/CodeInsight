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
int dx[] = {0, -1, 0, 1, 1, 1, -1, -1};
int dy[] = {-1, 0, 1, 0, 1, -1, 1, -1};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  string s;
  cin >> n >> m >> s;

  vvt<int> edge(n);
  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  vt<bool> ok(n, false);
  rep(cu, 0, n) {
    int a = 0, b = 0;

    for(auto to : edge[cu]) {
      if(s[to] == 'A') a++;
      else b++;
    }

    if(a && b) ok[cu] = true;
  }

  vt<int> acou(n, 0), bcou(n, 0);
  rep(cu, 0, n) {
    if(!ok[cu]) continue;

    for(auto to : edge[cu]) {
      if(!ok[to]) continue;

      if(s[to] == 'A') acou[cu]++;
      else bcou[cu]++;
    }
  }

  queue<int> ng;
  rep(cu, 0, n) {
    if(ok[cu] && (!acou[cu] || !bcou[cu])) {
      ng.push(cu);
      ok[cu] = false;
    }
  }

  while(!ng.empty()) {
    int cu = ng.front();
    ng.pop();

    for(auto to : edge[cu]) {
      if(!ok[to]) continue;

      if(s[cu] == 'A') acou[to]--;
      else bcou[to]--;

      if(!acou[to] || !bcou[to]) {
        ng.push(to);
        ok[to] = false;
      }
    }
  }

  rep(cu, 0, n) {
    if(ok[cu]) return cout << "Yes\n", 0;
  }
  cout << "No\n";
}
