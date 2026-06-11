#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {
  
  int A, B, C, X;
  cin >> A >> B >> C >> X;

  int ans = 0;
  rep(i,A+1) rep(j,B+1) rep(k,C+1) {
    if (i * 500 + j * 100 + k * 50 == X) ans++;
  }

  cout << ans << endl;

  return 0;
}