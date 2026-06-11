#include <bits/stdc++.h>
using namespace std;
int main(){
  double N;
  double P;
  cin >> N >> P;
  double n = pow(P,1/N);
  long int p = P;
  long int x = N;
  for(long int i = n + 10;i>0;i--){
    long int m = pow(i,x);
    if(p % m == 0){
      cout << i << endl;
      break;
    }
  }
}