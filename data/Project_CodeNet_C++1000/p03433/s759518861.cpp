#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A;
  cin >> N >> A;
  if(N <= A){
    
    
  cout << "Yes" << endl;
  }
  else {
    int x;
    x = N % 500;
      if(x <= A){
        cout << "Yes" << endl;
      }
    else {
  cout << "No" << endl;
    }
    }
}