#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  cin >> N >> A >> B;
  
  if(N<=20){
    cout << min(A*N,B) << endl;
  }
  
  if(N > 20){
    cout << B << endl;
  }
}
