#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   vector<int> X(N);
   for(int i=0;i<N;i++){
      cin>>X[i];
   }
   vector<pair<int,int>> result(N);
   for(int i=0;i<N;i++){
      result[i]=make_pair(X[i],i);
   }
   sort(result.begin(),result.end());
   vector<int> ans(N);
   for(int i=0;i<N;i++){
      if(i<N/2){
         ans[result[i].second]=result[N/2].first;
      }else{
         ans[result[i].second]=result[N/2-1].first;
      }
   }
   for(int i=0;i<N;i++){
      cout<<ans[i]<<endl;
   }
   return 0;
}