#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, a, b, c, d;
  cin >> N;
  
  a = N % 10;
  b = (N - a) % 100;
  c = (N - a - b * 10) % 1000;
  d = N -(a + b * 10 + c * 100);
  
  if (a - b == 0 && c - d == 0){
    cout << "Yes" << endl;
  }
  else if (a == b && b == c ){
    cout << "Yes" << endl;
  }
  else if (a == b && b == d){
    cout << "Yes" << endl;
  }
  else if (a== c && c == d){
    cout << "Yes" << endl;
  }
  else if (b == c &&  c == d){
    cout << "Yes" << endl;
  }

 else{
    cout << "No" << endl;
  }
}
