#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N,M;
   cin>>N>>M;
   long long N1=min(N,M);
   long long M1=max(N,M);
   if(N1==1&&M1==1) cout<<1<<endl;
   else if(N1==1&&M1!=1) cout<<M1-2<<endl;
   else cout<<(N1-2)*(M1-2)<<endl;
   return 0;
}