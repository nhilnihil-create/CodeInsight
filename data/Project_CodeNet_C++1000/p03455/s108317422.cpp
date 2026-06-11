#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  int b;
  cin >> a >> b;
  int c =  a * b / 2;
  if (a * b > 2 * c){
    cout << "Odd";
  }else{
    cout << "Even";
  }
}