#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int N;
   cin>>N;
   double x;
   string u;
   double sum=0.0;
   
   rep(i,N){
       cin>>x>>u;
       if(u=="JPY"){
           sum+=x;
       }
       else{
           sum+=x*380000.0;
       }
   }
  
   cout<<sum<<endl;
}