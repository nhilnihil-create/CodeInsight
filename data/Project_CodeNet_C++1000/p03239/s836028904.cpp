#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int N,T;
   cin>>N>>T;
   int c,t;
   int m=1010;
   rep(i,N){
       cin>>c>>t;
       if(t<=T){
           m=min(m,c);
       }
   }
   if(m==1010){
       cout<<"TLE"<<endl;
   }
   else{
       cout<<m<<endl;
   }
     
}