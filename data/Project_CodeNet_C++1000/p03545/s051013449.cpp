#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;

int main() {
  int S; cin >> S;
    int D = S%10; S /= 10;
    int C = S%10; S /= 10;
    int B = S%10; S /= 10;
    int A = S%10;  
  
  for (int bit=0; bit<(1<<3); bit++){
    int sum = A;
    char opB = '+', opC ='+', opD ='+';
      if(bit & (1<<0)) sum += B;
      else {opB = '-'; sum -=B;}
      if(bit & (1<<1)) sum += C;
      else {opC = '-'; sum -=C;}
      if(bit & (1<<2)) sum += D;
      else {opD = '-'; sum -=D;}
      
      if(sum == 7) {
        cout << A << opB << B << opC << C << opD << D << "=7" << endl;
        return 0;
      }
  }
  cout << "None" << endl;
  return 0;
}