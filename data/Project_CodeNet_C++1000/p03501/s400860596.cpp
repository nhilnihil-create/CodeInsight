#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  if(A*N <= B){
     cout << A*N << endl;
  }  
  else if(A*N > N){
     cout << B << endl;
  }
}
