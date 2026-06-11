#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int A,B,C,X;
   cin>>A>>B>>C>>X;
   
   int cnt=0;
   rep(i,A+1){
       int rest=X-500*i;
       rep(j,B+1){
           int rest2=rest-100*j;
           rep(k,C+1){
               int rest3=rest2-50*k;
               if(rest3==0){
                   cnt++;
               }
           }
       }
   }
   
   cout<<cnt<<endl;
  
}