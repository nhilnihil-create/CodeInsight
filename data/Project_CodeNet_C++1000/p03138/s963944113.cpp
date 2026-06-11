#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n,k;
  cin>>n>>k;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  vector<Int> cnt(50);
  for(Int i=0;i<n;i++)
    for(Int j=0;j<50;j++)
      cnt[j]+=(a[i]>>j)&1;

  Int ans=0;
  function<void(Int, Int, Int)> dfs=
    [&](Int x,Int v,Int f){
      if(x<0){
        chmax(ans,v);
        return;
      }
      if(f){
        dfs(x-1,v+max(cnt[x],n-cnt[x])*(1LL<<x),1);
        return;
      }
      if((k>>x)&1){        
        dfs(x-1,v+(cnt[x])*(1LL<<x),1);   // 0 
        dfs(x-1,v+(n-cnt[x])*(1LL<<x),0); // 1
      }else{
        dfs(x-1,v+(cnt[x])*(1LL<<x),0);   // 0
      }
    }; 
  dfs(49,0,0);
  cout<<ans<<endl;
  return 0;
}
