#include <bits/stdc++.h>
using namespace std;

unsigned long long f(unsigned long long a){
  if(a % 2 == 1){
    return (a + 1) /2 % 2;
  } else{
    return a ^ ((a+1)/2%2);

  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;

  unsigned long long A, B;
  cin >> A >> B;
  cout << (f(B)^f(A-1)) <<endl;
}