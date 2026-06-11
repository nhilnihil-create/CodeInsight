#include <bits/stdc++.h>
using namespace std;

int main() {
int N,A,B;
  cin >> N >> A >> B;
  int P1=N*A;
  if(P1>=B){
    cout << B <<endl;
  }
  else{
    cout << P1 << endl;
  }
}
