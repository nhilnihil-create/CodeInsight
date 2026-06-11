#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  

  if(N * A - B > 0){
    cout << B << endl;
   }else{
    cout << N * A << endl;
   }
}