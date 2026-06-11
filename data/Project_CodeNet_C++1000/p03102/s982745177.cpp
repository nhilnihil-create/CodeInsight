#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {

  int N, M, C; cin >> N >> M >> C;
  int B[M];
  rep(i,M) cin >> B[i];
  int A[N][M];
  rep(i,N)rep(j,M) cin >> A[i][j];

  int ans = 0;

  rep(i,N){
    ll sum = 0;
    rep(j,M) {
    sum += A[i][j] * B[j];
    }
    if(sum + C > 0) ans++;
  }
  cout << ans << endl;
	return 0;
}

