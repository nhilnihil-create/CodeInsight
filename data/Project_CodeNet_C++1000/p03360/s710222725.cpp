#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int A, B, C, K; cin >> A >> B >> C >> K;
  
  int maxNumber = max(A, max(B, C));
  
  int tmp = maxNumber;
  
  for (int i = 0; i < K; i++) tmp *= 2;
  
  cout << A + B + C + tmp - maxNumber << endl;
  
}