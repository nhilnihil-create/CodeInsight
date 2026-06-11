#include <bits/stdc++.h>
using namespace std;

int f(int n){
 if(n % 2 == 0) return n / 2;
  else return 3 * n + 1;
}

int main(void){
  int N, A, B;
  cin >> N;
  if(N == 1) cout << "Hello World";
  else {
    cin >> A >> B;
    cout << A + B;
  }
  return 0;
}