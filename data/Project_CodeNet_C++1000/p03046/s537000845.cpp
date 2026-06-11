#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  int m,k;
  cin >> m >> k;
  if (k >= (1<<m)) {
    cout << -1 << endl;
    exit(EXIT_SUCCESS);
  }
  if (m == 1 && k == 1) {
    cout << -1 << endl;
    exit(EXIT_SUCCESS);
  }
  if (k == 0) {
    rep(i,(1<<(m+1))) {
      printf("%d ", i/2);
    }
    printf("\n");
    exit(EXIT_SUCCESS);
  }
  int n = 1<<m;
  printf("%d ", k);
  rep(i,n) {
    if (i != k) printf("%d ", i);
  }
  printf("%d ", k);
  rep(i,n) {
    if (n-i-1 != k) printf("%d ", n-i-1);
  }
  printf("\n");
  return 0;
}
