#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main(){
  int a,b,c;
  cin  >> a >> b >> c;
  if (b / a  <= c){
    cout << b / a << '\n';
  }
  else{
    cout << c << '\n';
  }
  return 0; 
}