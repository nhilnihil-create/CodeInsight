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
  
  ll N, M;
  cin >> N >> M;

  if (N > 1 && M > 1) cout << (N - 2) * (M - 2) << endl;
  else if (N == 1 && M > 1) cout << (M - 2) << endl;
  else if (M == 1 && N > 1) cout << (N - 2) << endl;
  else cout << 1 << endl;

  return 0;
}