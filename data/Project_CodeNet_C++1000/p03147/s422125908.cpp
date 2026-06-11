#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N;
  cin >> N;

  int h[N];
  rep(i,0,N-1) cin >> h[i];

  int cnt = 0, i, j;
  for (i = 0; i < N;) {
    if (h[i] == 0) {
      i++;
      continue;
    }

    for (j = i; j < N; j++) {
      if (h[j] == 0) break;
      else h[j]--;
    }

    cnt++;
  }

  cout << cnt << endl;
  return 0;
}
