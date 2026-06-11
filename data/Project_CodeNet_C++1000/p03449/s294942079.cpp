#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
   vector<vector<int>> data(2, vector<int>(N));
 
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      cin >> data.at(i).at(j);
    }
  }
  
  vector<int>A(N,0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i > j){
        A.at(i) += data.at(0).at(j);
      }
      else if (i == j){
        A.at(i) += data.at(0).at(j) + data.at(1).at(j);
      }
      else if (i < j){
        A.at(i) += data.at(1).at(j);
      }
    }
  }
  sort(A.begin(), A.end());
  cout << A.at(N-1) << endl;
}
  

