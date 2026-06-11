#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
const int INF=1e20;

signed main(){
   int N,K;cin>>N>>K;
   vector<int>X(N);
   vector<int>Y(N);
   REP(i,N)cin>>X[i]>>Y[i];
   vector<int>Xc(N);
   vector<int>Yc(N);
   Xc=X;
   Yc=Y;
   sort(Xc.begin(),Xc.end());
   sort(Yc.begin(),Yc.end());
   int ans=INF;
   for(int i=0;i<N-1;i++){
       for(int j=i+1;j<N;j++){
           for(int k=0;k<N-1;k++){
               for(int l=k+1;l<N;l++){
                   int xl=Xc[i];
                   int xh=Xc[j];
                   int yl=Yc[k];
                   int yh=Yc[l];
                   int count=0;
                   for(int q=0;q<N;q++){
                       if(X[q]>=xl&&X[q]<=xh&&Y[q]>=yl&&Y[q]<=yh){
                           count++;
                       }
                   }
                   if(count>=K){
                       ans=min(ans,(xh-xl)*(yh-yl));
                   }
               }
           }
       }
   }
   cout<<ans<<endl;
}