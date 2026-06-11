#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int A;
  int B;
  
  cin >> N >> A >> B;
  int a_charge = A * N;
  if (a_charge > B) {
    cout << B << endl;
  }
  else {
    cout << a_charge << endl;
  }
}