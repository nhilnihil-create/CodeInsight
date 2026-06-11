#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
template<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
//end



int main(){
   ll n,x; cin>>n>>x;
   vector<ll> a(n); vector<__int128_t>sum(n+1,0);
   rep(i,0,n){
      cin>>a[i];
      sum[i+1]=sum[i]+a[i];
   }
   __int128_t res=INF;
   rep(k,1,n+1){
      __int128_t sub=k*x;
      int lb=n; int idx=1;
      while(lb>0){
         sub+=(sum[lb]-sum[max(lb-k,0)])*(idx==1?5:2*idx+1);
         lb-=k; idx++;
      } chmin(res,sub);
   }
   cout<<(ll)res+n*x<<endl;
   return 0;
}