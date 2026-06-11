#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  
  cin >> N >> A >> B;
  int T = A * N;
  
  if (T <= B) {
    cout << T << endl;
  }
  else if (T >= B){
    cout << B << endl;
  }
}
