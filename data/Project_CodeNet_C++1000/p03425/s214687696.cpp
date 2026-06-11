#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   vector<string> S(N);
   for(int i=0;i<N;i++){
      cin>>S[i];
   }
   long long count[5]={0};
   for(int i=0;i<N;i++){
      if(S[i][0]=='M') count[0]++;
      if(S[i][0]=='A') count[1]++;
      if(S[i][0]=='R') count[2]++;
      if(S[i][0]=='C') count[3]++;
      if(S[i][0]=='H') count[4]++;
   }
   long long ans=0;
   for(int i=0;i<5;i++){
      for(int j=i+1;j<5;j++){
         for(int k=j+1;k<5;k++){
            ans+=count[i]*count[j]*count[k];
         }
      }
   }
   cout<<ans<<endl;
   return 0;
}