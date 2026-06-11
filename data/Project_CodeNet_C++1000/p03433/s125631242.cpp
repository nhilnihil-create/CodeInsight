#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A,B;
  cin >> N >> A;
  
  B = N % 500;
  
  
  if (A >=  N % 500) {
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

}