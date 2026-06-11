#include <iostream>
using namespace std;

int main(){
  int a;
  int b;
	cin >> a >> b;
  a=a*b;
  a=a%2;
  if(a==0){
  	cout << "Even";
  }else{
  	cout << "Odd";
  }
}