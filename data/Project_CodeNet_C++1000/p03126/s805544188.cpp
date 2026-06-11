#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int N,M,K,X;
   cin>>N>>M;
   int cnt=0;
   map<int,int> A;
   rep(i,N){
       cin>>K;
       rep(j,K){
           cin>>X;
           A[X]++;
       }
   }
   for (auto p:A){
       
       auto v=p.second;
       if(v==N){
           cnt++;
       }
   }
   cout<<cnt<<endl;
}