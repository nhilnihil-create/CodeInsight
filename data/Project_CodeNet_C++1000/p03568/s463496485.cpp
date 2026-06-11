#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  int c1 = 1, c2 = 1;
  for (int i = 0; i < N; i++){
    c1 *= 3;
    cin >> A[i];
    if (A[i] % 2 == 0){
      c2 *= 2;
    }
  }
  cout << c1 - c2;
}