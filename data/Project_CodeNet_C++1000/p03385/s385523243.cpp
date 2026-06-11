#include <bits/stdc++.h>
using namespace std;

int main() {
  string A;
  cin >> A;
  if(A[0]!=A[1] && A[0]!=A[2] && A[1]!=A[2]){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }    
}
