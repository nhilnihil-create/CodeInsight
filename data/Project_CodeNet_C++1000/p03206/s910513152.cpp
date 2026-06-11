#include <bits/stdc++.h>
using namespace std;

int main() {
  int A;
  cin >> A;
  cout << "Christmas";
  A -= 25;
  while(A<0){
    cout << " Eve";
    A++;
  }
  cout << endl;
}