#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int A;
  	cin >> N >> A;
    int X;
  X = N * A % 2;

  if (X > 0) {
    cout << "Odd" << endl;
  }
  else if (X == 0){
    cout << "Even" << endl;
  }
     
}