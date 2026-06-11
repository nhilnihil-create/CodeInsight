#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int table[2][N]; int sum = 0;
  
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      cin >> table[i][j];
    }
  }
  
  for (int i = 0; i < N; i++) {
    
    int tmp = 0;
    
    for (int j = 0; j < i + 1; j++) tmp += table[0][j];
    
    for (int j = i; j < N; j++) tmp += table[1][j];
    
    sum = max(sum, tmp);
    
  }
  
  cout << sum << endl;
  
}