#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int dansuu = 0;
  
  int N;
  cin >> N;
  
  
  vector<int> d(N);
  for (int i = 0; i < N; i++) {
    
    cin >> d.at(i);
    
  }
  
  
    
    
  for (int i = 0; i < N; i++) {
    
    int a = d.at(i);
    
    if (a == 0) {
      
      continue;
      
    } else {
      
      dansuu++;
      
      for(int i = 0; i < N; i++) {
      
        if (a == d.at(i)) {
        
          d.at(i) = 0;
        
        } else {
        
          continue;
        
        }
      
      }
      
    }
    
    
    
  }
  
  cout << dansuu << endl;
  
}
 
  
  
