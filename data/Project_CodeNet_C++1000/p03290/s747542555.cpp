#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(void){
   int D,G;
   cin>>D>>G;
   vector<int> p(D),c(D);
   for(int i=0;i<D;i++){
      cin>>p[i]>>c[i];
   }
   int ans=10000;
   for(int i=0;i<(1<<D);i++){
      int sum=0;
      int cnt=0;
      int incomp=-1;
      for(int j=0;j<D;j++){
         if(i&(1<<j)){
            sum+=100*(j+1)*p[j]+c[j];
            cnt+=p[j];
         }else{
            incomp=j;
         }
      }
      if(sum<G){
         int sum_rest=G-sum;
         double rest=(double)sum_rest/(double)(100*(incomp+1));
         if(ceil(rest)>=p[incomp]) continue;
         cnt+=ceil(rest);
      }
      ans=min(ans,cnt);
   }
   cout<<ans<<endl;
   return 0;
}