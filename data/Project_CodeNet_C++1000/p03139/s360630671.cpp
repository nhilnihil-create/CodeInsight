#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,A,B; cin >> N >> A >> B;
  int D = min(A,B);
  int S;
  if(N>=A+B) S=0;
  else S=A+B-N;
  
  cout << D << " " << S << endl;
}