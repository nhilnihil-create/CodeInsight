#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int M=0, m=0;
  for (int i=0; i<(int)S.size(); i++) {
    m=0;
    for (int j=0; j<(int)S.size()-i; j++) {
      if (S[i+j]=='A' || S[i+j]=='T' || S[i+j]=='G' || S[i+j]=='C') {
        m++;
      }
      else {
        break;
      }
    }
    M=max(M, m);
  }
  cout << M << endl;
}

