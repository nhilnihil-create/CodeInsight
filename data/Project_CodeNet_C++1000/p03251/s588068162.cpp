#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, M, X, Y; cin >> N >> M >> X >> Y;
  
  vector<int> vecX(N); vector<int> vecY(M);
  
  for (int i = 0; i < N; i++) cin >> vecX[i];
  
  for (int i = 0; i < M; i++) cin >> vecY[i];
  
  sort(vecX.begin(), vecX.end()); sort(vecY.begin(), vecY.end());
  
  for (int i = X + 1; i < Y; i++) {
    if (vecX.back() < i && i <= vecY.front()) {
      cout << "No War" << endl;
      return 0;
    }
  }
  
  cout << "War" << endl;
  
}