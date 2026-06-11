#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin >> N >> M;
  
  vector<int>X(M);
  for (int i = 0; i < M; i++) {
    cin >> X.at(i);
  }
  sort(X.begin(), X.end());
  
  vector<int>Y(M-1);
  for (int i = 0; i < M-1; i++) {
    Y.at(i) = X.at(i+1) - X.at(i);
  }
  sort(Y.begin(), Y.end());
  int sum = 0;
  for (int i = 0; i < M-N; i++) {
    sum += Y.at(i);
  }
  cout << sum << endl;
}
  
  
  
  