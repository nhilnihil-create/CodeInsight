#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  
  int NA = N * A;
  
  if (NA > B){
    cout << B << endl;
  }else{
    cout << NA << endl;
  }

  return 0;
}