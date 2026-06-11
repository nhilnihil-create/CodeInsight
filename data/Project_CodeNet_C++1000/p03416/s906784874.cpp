#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A , B , M ,S ,H ,J ,I ,count;
  cin >> A >> B;
  count = 0;
  
  for(int x = A; x < B+1; x++){
    M = x;
    S = M % 10000;
    M = M / 10000;
  
    H = S % 1000;
    S = S / 1000;
    
    J = H % 100;
    H = H / 100;
  
    I = J % 10;
    J = J / 10;
    
    if(M == I && S == J){
      count ++;
    }
  }
  cout << count << endl;
  
}