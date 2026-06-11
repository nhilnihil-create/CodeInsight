#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  int A, B, C;
  cin >> A >> B >> C;
  if(A<B){
    if(A<C && C<B) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  else{
    if(B<C && C<A) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}