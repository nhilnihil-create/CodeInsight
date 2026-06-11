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
  vector<string> S(N);
  rep(i,N) cin >> S[i];

  int ans = 0;
  rep(A,N) {
    bool flag = true;
    for (int i = 1; i < N; i++) {
      for (int j = 0; j < i; j++) {
        if (S[(A + i) % N][j] != S[(A + j) % N][i]) flag = false;
      }
    }
    if (flag) ans += N;
  }

  cout << ans << endl;

  return 0;
}