#include<iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(){
  int nmin,nmax;
  cin >> nmin >> nmax;
  string num;
  int count=0;
  for(int i=nmin;i<=nmax;i++){
	num = to_string(i);
    if(num.at(0) == num.at(4) && num.at(1) == num.at(3)){
      count++;
    }
  }
  
  cout << count << endl;
}
  
