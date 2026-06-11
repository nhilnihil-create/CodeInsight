#include<bits/stdc++.h>
using namespace std;

int main(void){
   long long N,H,W;
   cin>>N>>H>>W;
   vector<long long> A(N),B(N);
   for(int i=0;i<N;i++){
      cin>>A[i]>>B[i];
   }
   long long ans=0;
   for(int i=0;i<N;i++){
      if(A[i]>=H&&B[i]>=W) ans++;
   }
   cout<<ans<<endl;
   return 0;
}
