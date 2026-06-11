#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N;
  
  int currentT = 0; int currentX = 0; int currentY = 0;
  
  vector<int> vecT(N), vecX(N), vecY(N);
  
  for (int i = 0; i < N; i++) {
    
    int t, x, y; cin >> t >> x >> y;
    
    vecT[i] = t; vecX[i] = x; vecY[i] = y;
    
  }
  
  for (int i = 0; i < N; i++) {
    
    int difT = vecT[i] - currentT;
    
    int difC = abs(vecX[i] - currentX) + abs(vecY[i] - currentY);
    
    if (difT < difC || difT % 2 != difC % 2) {
      cout << "No" << endl;
      return 0;
    }
    
    currentT = vecT[i]; currentX = vecX[i]; currentY = vecY[i];
    
  }
  
  cout << "Yes" << endl;
  
}