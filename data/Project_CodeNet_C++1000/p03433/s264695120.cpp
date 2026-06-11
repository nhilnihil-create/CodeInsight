#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;

  if (N / 500 == 0) {
    cout << "Yes";
  } 
  
  else {
    if ((N % 500) > A) {
      cout << "No";
    } else {
      cout << "Yes";
    }
  }
  
    
}