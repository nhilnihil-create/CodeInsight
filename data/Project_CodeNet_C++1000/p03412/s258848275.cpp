#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
   int N; scanf("%lld",&N);
   vector<int> a(N),b(N);
   for(int i=0;i<N;i++) scanf("%lld",&a[i]);
   for(int i=0;i<N;i++) scanf("%lld",&b[i]);

   int ans=0;
   for(int i=28;i>=0;i--){
      const int mod=1<<(i+1);
      for(int j=0;j<N;j++){
         a[j]%=mod;
         b[j]%=mod;
      }
      sort(b.begin(),b.end());

      int cnt=0;
      for(int j=0;j<N;j++){
         for(int k=0;k<2;k++){
            cnt+=lower_bound(b.begin(),b.end(),mod+k*mod-a[j])
                -lower_bound(b.begin(),b.end(),mod/2+k*mod-a[j]);
         }
      }
      if(cnt&1) ans|=1<<i;
   }
   printf("%lld\n",ans);
}
