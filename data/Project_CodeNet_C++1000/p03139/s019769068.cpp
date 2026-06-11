#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  cin >> N >> A >> B;
  if(A>B){
    cout << B;
  }
  else{
    cout << A;
  }
  cout << " ";
  if(A+B-N>0){
    cout << A+B-N << endl;
  }
  else{
    cout << 0 << endl;
  }
}
