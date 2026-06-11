#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int A = N%1110;
  int B = N%1000;
  if(A <= 10){
    cout << "Yes" <<endl;
  }
  else if(B%111 == 0){
        cout << "Yes" <<endl;
  }
  else{
        cout << "No" <<endl;
  }
}