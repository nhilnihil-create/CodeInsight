#include<bits/stdc++.h>

using namespace std;

 int main()
 {
   long int n,i,sum=0;
   cin>>n;
   i=n;

   while(i){
        sum+=(i%10);
        i/=10;

   }
   if(n%sum==0){cout<<"Yes"<<endl;}
   else {cout<<"No"<<endl;}

 }
