#include <bits/stdc++.h>
using namespace std;
  
int main() {
  int N;
  cin >> N;
  vector<int>D(N);
  for (int i = 0; i < N; i++) {
    cin >> D.at(i);
  }
  int M;
  cin >> M;
  vector<int>T(M);
  for (int i = 0; i < M; i++) {
    cin >> T.at(i);
  }
  sort(D.begin(), D.end());
  sort(T.begin(), T.end());
  
  int J = 0;
  for (int i = 0; i < M; i++) {
    for (int j = J; j < N; j++) {
      if (D.at(j) == T.at(i)){
        J = j + 1;
        break;
      }
      else if (j == N-1){
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
}
        
    
  
    
  