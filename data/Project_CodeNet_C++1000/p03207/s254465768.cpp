#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int N;
int P[15];

int main(){
  cin >> N;
  rep(i, N) cin >> P[i];

  sort(P, P+N);
  int ans = 0;
  rep(i, N-1) ans += P[i];
  ans += (P[N-1] / 2);

  cout << ans << endl;
}
