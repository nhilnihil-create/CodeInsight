#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int a,b;
 cin>>a>>b;
 int s;
 s = b-a;
 for(int i = 1; i <= 999; i++){
     int B;
     if(i%2 ==0){
         B = (1 + i)*i/2;
     }
     else {
         B = (1+i)*(i-1)/2+((i-1))/2+1;
     }
     int S;
     S = B-(B-i);
         if(S == s){
           cout<<B-b<<endl;
         }
     
 }
}