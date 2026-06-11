#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A ;
  B = N % 500 ;
  
  if (A-B >=0 ) {
    cout << "Yes" << endl;
  }
  if (A-B <0 ) {
    cout << "No" << endl;
  }
}
