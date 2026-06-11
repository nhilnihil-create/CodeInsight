#include <iostream>
#include <vector>
using namespace std;

int main(){
  int A;
  int B;
  cin >> A;
  cin >> B;
 if(A>=13){
  cout << B; 
 }else if(A>=6 && A<=12){
   cout << B/2;
 }else if(A<=5){
   cout << "0";
 }
	return 0;
}
