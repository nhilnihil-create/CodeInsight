#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
   int N; cin>>N;
   vector<double> t(N+1);
   vector<double> v(N+1);
   for(int i=0;i<N;i++) cin>>t[i+1];
   for(int i=0;i<N;i++) cin>>v[i];

   for(int i=0;i<N;i++){
      t[i+1]+=t[i];
   }
   v[N]=0;

   double curT=1;
   double preV=0.0;

   double ans=0.0;
   for(int i=0;i<N;i++){
      while(curT<=2*t[i+1]){
         double curV=preV+0.5;
         curV=min(curV,v[i]);
         for(int j=i+1;j<=N;j++){
            curV=min(curV,v[j]+(2*t[j]-curT)*0.5);
         }
         ans+=(preV+curV)*0.25;
         curT++;
         preV=curV;
      }
   }
   cout<<fixed<<setprecision(10)<<ans<<endl;
}
