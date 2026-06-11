#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,K;
  cin >> A >> B >> C >> K;
  int M = max(A,max(B,C));
  
  for (int i = 0; i < K; i++) {
    M *= 2;
  }
  cout << A + B + C + M - max(A,max(B,C)) << endl;
}

  