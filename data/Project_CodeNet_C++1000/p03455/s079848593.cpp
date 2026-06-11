#include <iostream>
#include <string> 
using namespace std; 
int main(){

 int a=0,b=0;
 int ans=0;
   
  cin >> a >> b ;
  ans = (a * b) % 2;
  if(ans == 1){
  	cout << "Odd" << endl;
  }else{
  	cout << "Even" << endl;
  }
  

}
