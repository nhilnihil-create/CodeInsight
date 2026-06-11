#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> D(N);
  rep(i,0,N-1) cin >> D[i];

  int M;
  cin >> M;

  vector<int> T(M);
  rep(i,0,M-1) cin >> T[i];

  sort(D.begin(), D.end());
  sort(T.begin(), T.end());

  int i = 0, j = 0;
  bool ok = true;
  while (i < N && j < M) {
    int d = D[i];
    int t = T[j];
    if (d == t) i++, j++;
    else if (t < d) {
      ok = false;
      break;
    } else i++;
  }

  if (ok) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
