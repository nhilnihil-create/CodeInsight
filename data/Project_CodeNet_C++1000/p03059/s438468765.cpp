#include<bits/stdc++.h>
using namespace std;

 int main()
 {

     int a,b,c,d,e,f;
     cin>>a>>b>>c;

     if(b>c)
        cout<<"0"<<endl;
     else
     {
         d=c/a;
         e=d*b;

         cout<<e<<endl;
     }

     return 0;
 }
