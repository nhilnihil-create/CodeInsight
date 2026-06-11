#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
int main(){
  ll N,M,i,a,b,c;scanf("%lld%lld",&N,&M);
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
  for(i=0;i<N;i++){
    scanf("%lld",&a);
    q.push(make_pair(a,1));
  }
  pair<ll,ll> t[M];
  for(i=0;i<M;i++) scanf("%lld%lld",&t[i].second,&t[i].first);
  sort(t,t+M,greater<pair<ll,ll>>());
  ll fc,fn,tn;
  for(i=0;i<M;i++){
    b = t[i].second;c = t[i].first;
    tn = 0;
    while(b){
      fc = q.top().first;fn = q.top().second;q.pop();
      if(fc >= c){
        q.push(make_pair(fc,fn));
        break;
      }
      if(fn <= b){
        tn += fn;
        b -= fn;
      } else {
        tn += b;
        q.push(make_pair(fc,fn-b));
      }
    }
    if(tn) q.push(make_pair(c,tn));
  }
  ll ans = 0;
  while(!q.empty()){
    ans += q.top().first*q.top().second;
    q.pop();
  }
  printf("%lld\n",ans);
}
