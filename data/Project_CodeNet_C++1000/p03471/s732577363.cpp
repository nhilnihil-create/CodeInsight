#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t N, Y; cin >> N >> Y;
  
  for (int i = 0; i <= N; i++) {
    
    for (int j = 0; j <= N - i; j++) {
      
      int Yukichi = i, Higuchi = j, Noguchi = N - i - j;
      
      if (Yukichi * 10000 + Higuchi * 5000 + Noguchi * 1000 == Y) {
        
        cout << Yukichi << " " << Higuchi << " " << Noguchi << endl;
        
        return 0;
        
      }
      
    }
    
  }
  
  cout << "-1 -1 -1" << endl;
  
}