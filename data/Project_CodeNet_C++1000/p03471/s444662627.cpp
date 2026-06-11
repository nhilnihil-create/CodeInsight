#include <bits/stdc++.h>
using namespace std;
 
int main(){ 
  
 int N,Y; 
 cin>>N>>Y;
 bool Q=false;
   
 for(int a=0;a<N+1;a++){
   for(int b=0;b<N-a+1;b++){
     int c=N-a-b;
       if(1000*a+5000*b+10000*c==Y){
         cout<<c<<" "<<b<<" "<<a<<endl;
         Q=true;
         break;
       }
     }
      if(Q){
        break;
      }
    }
     
     if(Q==false){
       cout<<-1<<" "<<-1<<" "<<-1;
     }
}
   
