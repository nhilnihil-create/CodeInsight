#include <iostream>
using namespace std;
int main()
{
     int a,b,s,m;
     cin>>a>>b;

     s=a+b;
     m=a*b;
     if(s==15){
        cout<<"+"<<endl;

     }else if(m==15){
         cout<<"*"<<endl;

     }else{
         cout<<"x"<<endl;

     }

  return 0;
}
