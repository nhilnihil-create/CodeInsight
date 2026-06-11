#include <bits/stdc++.h>
using namespace std;
#define rep(i,A) for(int i = 0;i < A;i++)

int main() {
  int A;
  cin >> A;
  if(A % 111 == 0){
  cout << A << endl;
  }
  else{
    cout << 111 + A / 111 * 111 << endl;
  }
}
