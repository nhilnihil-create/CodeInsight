#include<bits/stdc++.h>

using namespace std;

 int main()
 {
   long int num,i,s=0;
   cin>>num;
   i=num;

   while(i){
        s+=(i%10);
        i/=10;

   }
   if(num%s==0)
   {
       cout<<"Yes"<<endl;
    }
   else 
   {
       cout<<"No"<<endl;
       
   }

 }



