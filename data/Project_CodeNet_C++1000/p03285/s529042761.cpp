#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int N;
  cin >> N;
  
  for(int a=0; a<N; a++){
    for(int b=0; b<N; b++){
      int total = 4*a + 7*b;
      if(total == N){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  
  cout << "No" << endl;
}