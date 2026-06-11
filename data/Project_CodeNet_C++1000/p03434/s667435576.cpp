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
  
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,N) cin >> A[i];

  sort(A.rbegin(), A.rend());
  int ans = 0;
  rep(i,N) {
    ans += A[i] * (i % 2 == 0 ? 1 : -1);
  }

  cout << ans << endl;

  return 0;
}