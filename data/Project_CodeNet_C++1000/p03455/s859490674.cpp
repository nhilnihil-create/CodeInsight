#include<bits/stdc++.h>
using namespace std;
int main(void){

  int a=0,b=0;
  cin >> a >> b;
  int num = 0;
  num = a*b;
  if(num%2 == 0){
  	cout << "Even" << endl;
  }else{
  	cout << "Odd" << endl;
  }
}