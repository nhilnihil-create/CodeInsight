#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int A,B,K;
   cin>>A>>B>>K;
   map<int,int> data;
   rep(i,K){
       if(A+i>B){
           continue;
       }
       if(B-i<A){
           continue;
       }
       data[A+i]++;
   
       data[B-i]++;
   }
   for(auto D:data){
       auto k=D.first;
       cout<<k<<endl;
   }
  
}