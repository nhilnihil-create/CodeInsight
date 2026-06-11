#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> X(N), Y(N);
  rep(i,0,N-1) {
    cin >> X[i];
    Y[i] = X[i];
  }

  sort(X.begin(), X.end());
  int L = X[N/2-1], R = X[N/2];

  rep(i,0,N-1) {
    if (Y[i] <= L) cout << R << endl;
    else if (R <= Y[i]) cout << L << endl;
  }

  return 0;
}
