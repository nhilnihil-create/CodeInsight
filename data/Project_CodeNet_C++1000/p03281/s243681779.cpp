#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, C=0, m;
  cin >> N;
  for (int i=1; i<=N; i+=2) {
    m=0;
    for (int j=1; j<=i; j+=2) {
      if (i%j==0) {
        m++;
      } 
    }
    if (m==8) {
      C++;
    }
  }
  cout << C << endl;
} 
