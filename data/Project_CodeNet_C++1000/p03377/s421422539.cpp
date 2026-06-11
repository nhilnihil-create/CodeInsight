#include<iostream>
using namespace std;

int main(){
  int A, B, X;
  cin >> A >> B >> X;
  cout << (A+B>=X && A <= X? "YES" : "NO") << endl;
  return 0;
}
