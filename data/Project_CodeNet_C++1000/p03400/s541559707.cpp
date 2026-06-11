#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int N, D, X;
  cin >> N >> D >> X;
  vector<int> A(N);
  rep(i, 0, N) cin >> A.at(i);

  int Ans = X;
  rep(i, 0, N) Ans += 1 + (D-1)/A.at(i);

  cout << Ans << endl;
}
