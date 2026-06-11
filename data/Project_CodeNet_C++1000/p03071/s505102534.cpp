#include<iostream>
#include<algorithm>
#include <stdlib.h>
#include <locale>
using namespace std;
int main(){
  int i,a,b;
  cin >> a >> b;
  if(a-1>=b){
    cout << a+a-1 << endl;
  }
  else if(b-1>=a){
    cout << b+b-1 << endl;
  }
  else{
    cout << a*2 << endl;
  }
  return 0;
}
