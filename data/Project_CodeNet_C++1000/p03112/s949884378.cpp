#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  Int a,b,q;
  cin>>a>>b>>q;
  vector<Int> s(a),t(b),x(q);
  for(Int i=0;i<a;i++) cin>>s[i];
  for(Int i=0;i<b;i++) cin>>t[i];
  for(Int i=0;i<q;i++) cin>>x[i];

  const Int INF = 1e14;
  s.emplace(s.begin(),-INF);
  s.emplace(s.begin(),-INF*2);
  s.emplace_back(INF);
  s.emplace_back(INF*2);
  
  t.emplace(t.begin(),-INF);
  t.emplace(t.begin(),-INF*2);
  t.emplace_back(INF);
  t.emplace_back(INF*2);

  for(Int i=0;i<q;i++){
    Int u=lower_bound(s.begin(),s.end(),x[i])-s.begin();
    Int v=lower_bound(t.begin(),t.end(),x[i])-t.begin();
    
    Int res=INF;
    for(Int j=-1;j<=1;j++){
      for(Int k=-1;k<=1;k++){
        chmin(res,abs(s[u+j]-x[i])+abs(t[v+k]-s[u+j]));
        chmin(res,abs(t[v+k]-x[i])+abs(s[u+j]-t[v+k]));
      }
    }
    cout<<res<<"\n";
  }
  cout<<flush;
  return 0;
}
