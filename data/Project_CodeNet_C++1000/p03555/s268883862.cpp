#include <bits/stdc++.h>
using namespace std;

int main(){
  string A,B;
  cin >> A >> B;
  swap(A[0],A[2]);
  
  if(A==B){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}
