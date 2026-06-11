#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int A ,B ;
  string S, T;
  cin >> A >> B;
  if(B % A == 0) cout << A + B << endl;
  else cout << B - A << endl;
}
