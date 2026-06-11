#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;
  int x = N%500;
   
  if ( x > A) {
    cout << "No" << endl;
  }
  if ( x <= A)  {
    cout << "Yes" << endl;
}
}
    