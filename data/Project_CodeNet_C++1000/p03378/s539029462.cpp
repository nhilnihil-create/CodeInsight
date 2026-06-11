#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int N,M,X;
   cin>>N>>M>>X;
   int A[M];
   
   int ans0,ansN;
   rep(i,M){
       cin>>A[i];
       if(X<A[i]){
           ans0=i;
           ansN=M-i;
           break;
       }
   }
   int ans=min(ans0,ansN);
   cout<<ans<<endl;
    
}