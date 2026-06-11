#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A;
  cin >> N >> A;
  
  if(N % 500 <= A && N != 0){
    cout << "Yes" << endl;
  }
  
  else {
    cout << "No" << endl;
  }
}