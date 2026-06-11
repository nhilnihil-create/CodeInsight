#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,x1,x2,x3,x4;
 

  cin >> N;
 
  x1 = N - N / 10 * 10;
  x2 = N / 10 - N / 100 * 10;
  x3 = N / 100 - N / 1000 * 10;
  x4 = N / 1000;
    
    if(x1 == x2 && x2 == x3){
      cout << "Yes";
    }
  else if(x2 == x3 && x3 == x4){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}
