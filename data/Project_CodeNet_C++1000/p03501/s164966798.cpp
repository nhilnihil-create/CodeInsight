#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,A,B;
  cin >> N >> A >> B;
  if (N * A > B || N * A == B) {
    cout << B << endl;
  } else if (N * A < B){
    cout << N * A << endl;
  } else {
    cout << "error" << endl;
  }
  return 0;
}