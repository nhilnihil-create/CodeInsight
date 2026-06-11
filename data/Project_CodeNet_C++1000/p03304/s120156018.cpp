#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  double n, m, d;
  cin >> n >> m >> d;
  double ans = 0;
  if (d == 0) ans = 1 / n;
  else ans = 2 * (n - d) / (n * n);
  ans *= (m - 1);

  printf("%.9f\n", ans);
}