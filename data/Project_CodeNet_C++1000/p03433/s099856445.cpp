#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,A,a;
  cin >> N >> A;
  a = N / 500;
  if (A == 0){
    if (N % 500 == 0){
      cout << "Yes";
    } else {
      cout << "No";
    }
  }else{
    if (N < A) {
      cout << "Yes" << endl;
    }else{
      if (N - a * 500 < A ) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl ;
      }
    }
  }
  
  
  return 0;
}