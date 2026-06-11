#include<bits/stdc++.h>

using namespace std;

int main(){
  int A,B;
  cin >> A;
  cin >> B;
  A %= 500;
  if(A <= B){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
