#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int M = sqrt(N);
  
  if (M*M == N){
    cout << N << endl;
  }
  else {
    cout << M*M << endl;
  }
}
  