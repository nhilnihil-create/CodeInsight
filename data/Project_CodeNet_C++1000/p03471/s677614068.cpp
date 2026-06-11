#include <bits/stdc++.h>

using namespace std;

int main()
{
   
   long long n,Y,t,f,o = -1;
   
   cin>>n>>Y;
   
   Y = Y / 1000;
   
   for(t = 0 ; t <= n ; t++){
       for(f = 0 ; f <= n-t ; f++){
           if(9*t+4*f+n-Y==0){
               o = n - f - t;
               break;
           }
       }
       if(o!=-1) break;
   }
   
   if(o==-1){
       cout<<"-1 -1 -1";
   } else
    cout<<t<<' '<<f<<' '<<o;
   
   return 0;
}