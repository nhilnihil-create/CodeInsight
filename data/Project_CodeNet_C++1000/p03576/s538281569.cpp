#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main(){
   int N,K;
   cin>>N>>K;
   using P=pair<ll,ll>;
   vector<P> v(N);
   for(int i=0;i<N;++i) cin>>v[i].first>>v[i].second;
   sort(v.begin(),v.end());
   
   ll ans=1LL<<62;
   for(int a=0;a<N;++a){
      for(int b=0;b<N;++b){
         ll ly=v[a].second,ry=v[b].second;
         if(ly>ry) continue;
         for(int c=0;c<N;++c){
            if(!(ly<=v[c].second && v[c].second<=ry)) continue;
            ll lx=v[c].first;
            ll rx;
            int cnt=1;
            for(int d=c+1;d<N&&cnt<K;++d){
               if(ly<=v[d].second && v[d].second<=ry){
                  cnt++;
                  rx=v[d].first;
               }
            }
            if(cnt<K) continue;
            
            ans=min(ans,(rx-lx)*(ry-ly));
         }
      }
   }

   cout<<ans<<endl;
}
