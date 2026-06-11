#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,X;
  cin >> N >> M >> X;
  
  vector<int> A(M);
  for (int i = 0; i < M; i++) {
    cin >> A.at(i);
  }
  
  int counta = 0;
  int countb = 0;
  
  for (int i = 0; i < M; i++) {
    if (A.at(i) < X) {
      counta++;
    }
    else {
      countb++;
    }
  }
  
  if (counta > countb) {
    cout << countb << endl;
  }
  else {
    cout << counta << endl;
  }
}