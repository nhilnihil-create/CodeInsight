#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int C = 1;
  cin >> N;
  vector<int> M(N);
  
  for (int i = 0; i < N; i++) {
    cin >> M.at(i);
  }
  
  sort(M.begin(), M.end());
  for (int i = 0; i < N - 1; i++) {
    if (M.at(i) != M.at(i + 1)) {
      C++;
    }
  }
  
  cout << C << endl;
  
}