#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, N;
  cin >> N;
  cin >> A;
 
  if (N / 500 == 0) {
    cout << "Yes" << endl;
  }else{
    if(N % 500 <= A){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
 }