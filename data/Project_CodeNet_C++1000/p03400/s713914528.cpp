#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int N,D,X;
   cin>>N>>D>>X;
   int A[N];
   
   rep(i,N){
       cin>>A[i];
   }
   int sum=X;
   rep(i,N){
       int num=1;
       while(num<=D){
           num+=A[i];
           sum++;
       }
   }
   cout<<sum<<endl;
  
}