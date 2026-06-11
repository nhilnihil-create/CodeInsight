#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 0, A = 0, B = 0;
  cin >> N >> A >> B;
  int AT = N * A;
  if( AT < B ){
    cout << AT << endl;
  }
  else{
    cout << B << endl;
  }
}