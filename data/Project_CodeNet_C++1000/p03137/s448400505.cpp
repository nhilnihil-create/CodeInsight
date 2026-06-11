#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int N, M;
int X[100010];
int Y[100010];
int ans;

int main(){
  cin >> N >> M;
  rep(i, M) cin >> X[i];
  sort(X, X+M);

  rep(i, M-1) Y[i] = abs(X[i+1] - X[i]);
  sort(Y, Y+M-1);

  if (M <= N) cout << 0 << endl;
  else{
    rep(i, M-N) ans += Y[i];
    cout << ans << endl;
  }
}
