#include<iostream>
using namespace std;

int main(){
  int A, B, sum = 0;
  int i = 0;
  
  cin >> A >> B;
  while(i<=1){
  	if(A > B){
    	sum += A;
    	A -= 1;
  	}
  	else{
    	sum += B;
    	B -= 1;
  	}
    i += 1;
  }
  cout << sum << endl;
}