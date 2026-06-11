#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
   if(a%b==0){
      return b;
   }else{
      return gcd(b,a%b);
   }
}
int main(void){
   long long N,M;
   cin>>N>>M;
   string S,T;
   cin>>S>>T;
   long long result=M/gcd(N,M)*N;
   int n=N/gcd(N,M);
   int m=M/gcd(N,M);
   bool flag=true;
   for(int i=0;i<gcd(N,M);i++){
      int temp1=n*i;
      int temp2=m*i;
      if(S[temp1]!=T[temp2]){
         flag=false;
         break;
      }
   }
   if(flag) cout<<result<<endl;
   else cout<<-1<<endl;
   return 0;
}
