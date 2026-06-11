#include <iostream>
#include <string>
using namespace std;

int main(){
  int i, price = 700;
  string s;
  cin >> s;
  for( i=0; i<3; i++ ){
    if( s[i]=='o' ){
      price += 100;
    }
  }
  cout << price << endl;
}
