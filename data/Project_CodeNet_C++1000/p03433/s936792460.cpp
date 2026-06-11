#include <bits/stdc++.h>
using namespace std;

int main() {
  int N , A , B;
  cin >> N >> A;
  B = N % 500;
  
  if (B == 0) {
    cout << "Yes" << endl;
  }
  else if (B < A) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  

}