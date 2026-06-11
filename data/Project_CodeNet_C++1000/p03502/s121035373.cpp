#include<iostream>
using namespace std;
int digit(int n){
   int H=0;
  	while(n!=0){
		H+=n%10;
    	n=n/10;
 	 }
    return H;
  }
  int main(){
    int n;
    cin >> n;
  if(n%digit(n)==0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;
}