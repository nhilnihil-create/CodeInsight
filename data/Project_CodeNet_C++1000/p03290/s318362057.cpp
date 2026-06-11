#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG 

int main(){
   int d,g;
   cin>>d>>g;
   ll p[d];
   ll c[d];
   ll sum[d];
   rep(i,d){
       cin>>p[i]>>c[i];
       sum[i]=100*(i+1)*p[i]+c[i];
   }

   ll ans= INF;
   for(int bit=0;bit<(1<<d); bit++){
       ll a=0;
       int b=-1;
       ll pans=0;
       //aは暫定の合計、bは全部解かない問題のうち一番得点が高い物、pansは解いた問題数の暫定
       rep(i,d){
           if(bit&(1<<i)){
               a+=sum[i];
               pans+=p[i];
           }
           else b=max(b,i);
       }
       if(a>=g) ans=min(ans,pans);
       else {
           int count=0;
           while(count<p[b]&&a<g){
               a+=100*(b+1);
               count++;
               pans++;
           }
           if(a>=g) ans=min(ans,pans);
           else continue;

       }
   }

   cout<<ans<<endl;

}