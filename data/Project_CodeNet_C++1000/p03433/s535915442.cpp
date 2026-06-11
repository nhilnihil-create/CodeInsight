#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, N;
    cin >> N >> A;
  if ( N % 500 != 0 && ( N % 500 ) > A) {
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;  
  }
}