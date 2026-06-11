#include <iostream>
using namespace std;
int main(void){
    int a,b,z;
    cin>>a>>b;
    z=a+b;
    if(z%2==0){
        cout<<z/2<<endl;
      }
 else if(z%2>0){
   cout<<z/2+1<<endl;  
  }
        else{
            cout<<z/2<<endl;
        }
    
}