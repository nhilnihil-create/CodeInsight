#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, a, B, A;
  cin >> N >> a >> B;
  A = N*a;
  if(A > B)cout << B << endl;
  else if(A < B)cout << A << endl;
  else{cout << A << endl;}
}