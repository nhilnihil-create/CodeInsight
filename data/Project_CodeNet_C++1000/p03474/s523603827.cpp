#include<bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  string S;
  cin >> A >> B >> S;
  bool ok = true;
  
  int i = 0;
  while(i < A + B + 1) {
    if(i == A && S[i] != '-') {
      cout<< "No" << endl;
      ok = false;
      break;
    }
    else if(i != A && S[i] == '-') {
      cout << "No" << endl;
      ok = false;
      break;
    }
    i++;
  }
  
  if(ok == true) cout << "Yes" << endl;
}