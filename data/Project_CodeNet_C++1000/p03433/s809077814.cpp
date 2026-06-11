#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, N;
  cin >> N  >> A;
  int b = N%500;
  if (b == 0) {
    cout << "Yes";
  }else{
    if(b <= A){
      cout << "Yes";
    }else{
      cout << "No";
    }
  }
}