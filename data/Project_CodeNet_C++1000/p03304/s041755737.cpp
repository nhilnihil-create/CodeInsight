#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define p_ll pair<ll, ll>
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  double n, m, d; cin >> n >> m >> d;
  double num = d ? (n-d)*2 : n;
  double result = num*(m-1)/(n*n);
  cout << fixed << result << endl;
  return 0;
}