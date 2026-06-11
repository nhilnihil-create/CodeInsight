#include <bits/stdc++.h>
using namespace std;



int main(){
   
    int M=100010;
   vector<int> prime(M,1);
   prime.at(0)=0; prime.at(1)=0;
   for(int i=2;i<M;i++){
     if(prime.at(i)==0){
         continue;
     }
     for(int j=i*2;j<M;j+=i){
         prime.at(j)=0;
     }
   
   } 
   vector<int> A(M,0);
   for(int i=3;i<M;i++){
       if(prime.at(i)==1&&prime.at((i+1)/2)==1){
           A.at(i)=1;
       }
   }
   vector<int> R(M+1,0);
   for(int i=0;i<M;i++){
       R.at(i+1)=R.at(i)+A.at(i);
   }
   int Q; cin>>Q;
   for(int i=0;i<Q;i++){
       int l,r;
       cin>>l>>r;
       cout<<R.at(r+1)-R.at(l)<<endl;
   }
}