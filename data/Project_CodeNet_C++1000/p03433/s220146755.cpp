#include<bits/stdc++.h>
using namespace std;
int main(void){

  int N=0,A=0;
  cin >> N >> A;
  int num1=0, num2=0;
  num1=N/500;
  num1 = N-num1*500;
  if(num1 <= A){
  	cout << "Yes" << endl;
  }else{
  	cout << "No" << endl;
  }


}