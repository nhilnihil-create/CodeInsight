#include <iostream>
#include <string> 
using namespace std; 
int main(){

 string n1,n2,n3,n4;
 string N;
  cin >> N ;
  n1=N[0];
  n2=N[1];
  n3=N[2];
  n4=N[3];
  if(n1==n2 && n2==n3){
  	cout << "Yes" << endl;
  }else if(n2==n3 && n3==n4){
  	cout << "Yes" << endl;
  }else if(n1==n2 && n3==n4 && n1==n4){
   cout << "Yes" << endl;
  }else{
  	cout << "No" << endl;
  }
  

}
