#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,total=0;
  cin >> N;
  
  int AA;
  cin >> AA;
  
  while (AA%2 == 0) {
    AA /= 2;
    total++;
  }
  
  
  for (int i=0; i<(N-1); i++) {
    int A, sum=0;
    cin >> A;
    
    while (A%2 == 0) {
      A /= 2;
      sum++;
    }
    
    if (total >= sum) {
      total =sum;
    }
  }
  
  cout << total << endl;
  
}  