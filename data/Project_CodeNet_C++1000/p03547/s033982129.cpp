#include<iostream>
using namespace std;

int main(){
  char a, b, c;
  cin >> a >> b;
  if(a == b){
    c = '=';
  }
  else if(a > b){
    c = '>';
  }
  else{
    c = '<';
  }
  cout << c << endl;
  return 0;
}