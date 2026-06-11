#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   int ans=0;
   for(int i=1;i*i<=N;i++){
      ans=max(ans,i);
   }
   cout<<ans*ans<<endl;
   return 0;
}

