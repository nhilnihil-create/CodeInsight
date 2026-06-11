#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   vector<int> a(N);
   for(int i=0;i<N;i++){
      cin>>a[i];
   }
   map<int,int> result;
   for(int i=0;i<N;i++){
      result[a[i]]++;
   }
   int ans=0;
   for(int i=0;i<N;i++){
      if(result[a[i]]==a[i]) continue;
      else{
         result[a[i]]--;
         ans++;
      }
   }
   cout<<ans<<endl;
   return 0;
}