#include<iostream>
 
using namespace std;
 
int main(){
  int A, B, X;
  cin >> A >> B >> X;
  
  if (A + B < X) {
    cout << "NO\n";
  }
  else if (A > X) {
    cout << "NO\n";
  }
  else {
    cout << "YES\n";
  }
}