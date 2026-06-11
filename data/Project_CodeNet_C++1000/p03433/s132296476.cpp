#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A;
  int mod;
  
  cin >> N >> A;
  
  mod = N % 500;
  
  if ( A < mod){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }
  
}  