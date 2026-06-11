#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   vector<double> a(N);
   for(int i=0;i<N;i++){
      cin>>a[i];
   }
   double average=0.0;
   for(int i=0;i<N;i++){
      average+=a[i];
   }
   average/=N;
   int ans=N;
   double dist=average;
   for(int i=0;i<N;i++){
      dist=min(dist,abs(a[i]-average));
   }
   for(int i=0;i<N;i++){
      if(dist==abs(a[i]-average)){
         ans=min(ans,i);
      }
   }
   cout<<ans<<endl;
   return 0;
}
