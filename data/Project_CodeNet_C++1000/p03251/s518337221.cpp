#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, x, y;
  cin >> N >> M >> x >> y;
  vector<int> X(N), Y(M);
  for (int i=0; i<N; i++) {
    cin >> X[i];
  }
  for (int i=0; i<M; i++) {
    cin >> Y[i];
  }
  
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  
  if ((x<y && max(x, X[N-1])<min(y, Y[0])) || (x>y && min(x, X[0])>max(y, Y[M-1]))) {
    cout << "No War" << endl;
  }
  else {
    cout << "War" << endl;
  }

}
