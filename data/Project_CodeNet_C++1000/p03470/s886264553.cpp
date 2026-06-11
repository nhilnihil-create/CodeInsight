#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int dansuu = 1;
  
  int N;
  cin >> N;
  
  
  vector<int> d(N);
  for (int i = 0; i < N; i++) {
    
    cin >> d.at(i);
    
  }
  
  sort(d.begin(), d.end());
  
 
  
  int a =  d.at(0);
  
  for (int i = 0; i < N; i++){
    
    if (a != d.at(i)) {
      
      dansuu++;
      
      a = d.at(i);
      
    } else if (a == d.at(i)) {
      
      continue;
      
    }
    
  }
  cout << dansuu << endl;
  
}