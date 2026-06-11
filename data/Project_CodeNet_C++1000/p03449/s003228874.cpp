#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<vector<int>> data(2, vector<int>(100));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      cin >> data.at(i).at(j);
    }
  }
  int result = 0;
  for (int i = 0; i < N; i++) {
    int total = 0;
    for (int j = 0; j <= i; j++) {
      total += data.at(0).at(j);
    }
    for (int j = i; j < N; j++) {
      total += data.at(1).at(j);
    }
    if (total > result) {
      result = total;
    }
  }
  
  cout << result << endl;
      
  return 0;
}