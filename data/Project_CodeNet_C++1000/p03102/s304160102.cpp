#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int N, M, C;
int B[30];
int A[30][30];

int main(){
  cin >> N >> M >> C;
  rep(i, M) cin >> B[i];
  rep(i, N){
    rep(j, M) cin >> A[i][j];
  }

  int ans = 0;
  rep(i, N){
    int sums = 0;
    rep(j, M){
      sums += B[j] * A[i][j];
    }
    if (sums + C > 0) ans++;
  }
  cout << ans << endl;
}
