#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,X;
  cin >> A >> B >> X;
  if(A+B<X){
    cout << "NO" << endl;
    return 0;
  }
  if(A>X){
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}
