#include <bits/stdc++.h>
using namespace std;

void chmax(int& a, int b) {
  if (a < b) a = b;
}


int main() {
  int N;
  cin >> N;
  int Shop[N+1][11];
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= 10; j++) {
      cin >> Shop[i][j];
    }
  }
  
  int P[N+1][11];
  
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= 10; j++) {
      cin >> P[i][j];
    }
  } 
  
  int ans = -1000000000;
  
  
  for (int i = 1; i < 1024; i++) {
    int benefit = 0;
    // 店jとの利益
    for (int j = 1; j <= N; j++) {
      int count = 0;
      for (int k = 0; k < 10; k++) {
        if ((i & (1 << k)) && Shop[j][k+1]) count++;
      }
      benefit += P[j][count];
    }
    chmax(ans, benefit);
  }
  
  cout << ans << endl;
  
}