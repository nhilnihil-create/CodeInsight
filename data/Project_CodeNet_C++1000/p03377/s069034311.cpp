#include<bits/stdc++.h>
using namespace std;


int main(){
  
  long long A, B, X;
  cin >> A >> B >> X;
  
  if(A + B < X || A > X){
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}