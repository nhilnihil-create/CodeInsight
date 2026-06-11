#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int N;
   cin>>N;
   int L[N];
   int sum=0;
   int M=0;
   rep(i,N){
       cin>>L[i];
       M=max(M,L[i]);
       sum+=L[i];
   }
   sum-=M;
   if(M<sum){
       cout<<"Yes"<<endl;
   }
   else{
       cout<<"No"<<endl;
   }
   
}