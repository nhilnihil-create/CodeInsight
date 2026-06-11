#include <bits/stdc++.h>
using namespace std;

int main() {
  int A = 0, B = 0, N = 0;
  cin >> N >> A >> B;
  
  if(N * A > B) {
    cout << B << endl;
  }else if(N * A < B) {
    cout << N * A << endl;
  }else{
    cout << B << endl;
  }
}
