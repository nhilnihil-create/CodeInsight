#include <iostream>
using namespace std;

int main(){
  int n;
  int a,b;
  cin >> n >> a >> b;
  int c;
  if(a > b){
    cout << b << '\n';
  }else{
    cout << a << '\n';
  }
  c = a + b;
  if(n < c){
    cout << c - n;
  }else{
    cout << 0;
  }
  return 0;
}
