#include <iostream>
#include <string> 
using namespace std; 
int main(){

 int a=0,b=0,time=0;
 int ans=0;
   
  cin >> time >> a >> b ;
  ans = time * a ;
  if(ans < b){
  	cout << ans  << endl;
  }else{
  	cout << b << endl;
  }
  

}
