#include <iostream>
#include <string> 
using namespace std; 
int main(){

 int a=0,b=0,c=0,d=0;
 int l=0,r=0;
   
  cin >> a >> b >> c >> d ;
  l=a+b;
  r=c+d;
  if(l > r){
  	cout << "Left" << endl;
  }else if(l < r){
  	cout << "Right" << endl;
  }else{
  	cout << "Balanced" << endl;
  }
  

}
