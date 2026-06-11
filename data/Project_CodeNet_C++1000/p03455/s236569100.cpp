#include <iostream>
#include <string>
using namespace std;
 
int main(){
  int a, b;
  int result;
  string s;
  cin >> a >> b;
  result = (a * b) % 2;
  if (result == 1){
    s = "Odd";
  } else{
    s = "Even";
  }
  cout << s << endl;
}