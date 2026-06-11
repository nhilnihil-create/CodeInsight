#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> sta(N-1,vector<int>(3));
  for (int i = 0; i < N-1; i++) {
    for (int j = 0; j < 3; j++) cin >> sta[i][j];
  }
  
  for (int i = 0; i < N-1; i++) {
    int T = sta[i][1];
    for (int j = i; j < N-1; j++) {
      if (T < sta[j][1]) T = sta[j][1];
      else if (T%sta[j][2] != 0) T = T-(T%sta[j][2])+sta[j][2];
      T += sta[j][0];
    }
    cout << T << endl;
  }
  cout << 0 << endl;
}