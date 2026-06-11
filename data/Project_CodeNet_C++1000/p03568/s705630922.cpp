#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   vector<int> A(N);
   for(int i=0;i<N;i++){
      cin>>A[i];
   }
   long long ans=1;
   long long reject=1;
   for(int i=0;i<N;i++){
      ans*=3;
      if(A[i]%2==0) reject*=2;
   }
   cout<<ans-reject<<endl;
   return 0;
}
