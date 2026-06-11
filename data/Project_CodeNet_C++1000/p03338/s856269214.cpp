#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  string S;
  cin >> N >> S;
  
  vector<int>A(N);
  for (int i = 0; i < N; i++) {
    A.at(i) = S.at(i) - '0';
  }
  
  vector<vector<int>> data(26, vector<int>(N));
  for (int i = 0; i < 26; i++) {
    int count = 0;
    for (int j = 0; j < N; j++) {
      if (A.at(j) == i+49){
        count++;
      }
      data.at(i).at(j) = count;
    }
  }
  
  vector<int>B(N-1);
  for (int i = 0; i < N-1; i++) {
    int count = 0;
    for (int j = 0; j < 26; j++) {
      if (data.at(j).at(i) > 0 && data.at(j).at(N-1) - data.at(j).at(i) > 0){
        count++;
      }
    }
    B.at(i) = count;
  }
  sort(B.begin(), B.end());    
  cout << B.at(N-2) << endl;
}
   