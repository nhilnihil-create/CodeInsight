#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  double n, m, d;
  cin >> n >> m >> d;
  double ans;
  if(d == 0) {
    ans = (m - 1) * n / pow(n, 2);
  } else {
    ans = (m - 1) * 2 * (n - d) / pow(n, 2);
  }
  printf("%.9f\n", ans);
}