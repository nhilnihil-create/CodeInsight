#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int c=0;
  int m=10000000;
  for (int i=0; i<(int)S.size()-2; i++) {
    c=0;
    for (int j=0; j<3; j++) {
      c+=(S[i+j]-'0')*pow(10, 2-j);
    }
    m=min(m, abs(753-c));
  }
  cout << m << endl;
}

