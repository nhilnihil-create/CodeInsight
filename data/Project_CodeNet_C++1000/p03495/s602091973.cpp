#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N,K;
   cin>>N>>K;
   vector<int> A(N);
   for(int i=0;i<N;i++){
      cin>>A[i];
   }
   vector<int> result(N+1,0);
   for(int i=0;i<N;i++){
      result[A[i]]++;
   }
   int ans=0;
   sort(result.begin(),result.end());
   for(int i=0;i<N+1;i++){
      if(result[i]>=1) ans++;
   }
   if(ans<=K){
      cout<<0<<endl;
   }else{
      int count=0;
      for(int i=0;i<N+1;i++){
         if(result[i]>=1){
            count+=result[i];
            ans=ans-1;
         }
         if(ans<=K) break;
      }
      cout<<count<<endl;
   }
   return 0;
}