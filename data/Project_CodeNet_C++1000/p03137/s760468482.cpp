#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M, i, cnt = 0;
  cin >> N >> M;
  vector<int> X(M), dX(M - 1);
  for(i = 0; i < M; i++) cin >> X[i];
  sort(X.begin(), X.end());
  for(i = 0; i < M - 1; i++) dX[i] = X[i + 1] - X[i];
  sort(dX.begin(), dX.end());
  for(i = 0; i < max(0, M - N); i++) cnt += dX[i];
  cout << cnt << endl;
  return 0;
}