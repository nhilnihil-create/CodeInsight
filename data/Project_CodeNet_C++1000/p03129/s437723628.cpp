#include <bits/stdc++.h>
using namespace std;

int main() {
 int  N,K;
   cin >> N >> K;
  
  if (((N%2 == 1) && ((N+1)/2 >= K)) ||((N%2 == 0) && ((N)/2 >= K))){
    
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}
  
    
  

 
