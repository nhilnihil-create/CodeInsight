#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using ll = long long int;
using vec = vector<int>;
const int INF = 1e9+7;

int main() {
  int n, k; cin >> n >> k;
  vec v(n);
  rep(i,n) {
    cin >> v[i];
  }

  int m = 0;

  vec o;
  int sum_a = 0;
  rep(a, min(n,k)+1) {
    int sum_b = 0;
    vec o1 = o;
    rep(b, min(n,k)-a+1) {
      sort(all(o1));

      int sum_c = 0;
      rep(i, min(k-a-b, a+b)+1) {
        m = max(m, sum_a + sum_b - sum_c);
        if (i < a+b) sum_c += o1[i];
      }
      if (n-b-1 >= 0) {
        o1.push_back(v[n-b-1]);
        sum_b += v[n-b-1];
      }
    }
    if (a < n) {
      o.push_back(v[a]);
      sum_a += v[a];
    }
  }

  cout << m << endl;
}
