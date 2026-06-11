#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
int main(){
  ll N,C,i,j,x,v;scanf("%lld%lld",&N,&C);
  ll nowr = 0,nowl = 0;
  pair<ll,ll> S[N],R[N+1],R2[N+1],L[N+1],L2[N+1];
  for(i=0;i<N;i++) scanf("%lld%lld",&S[i].first,&S[i].second);
  R[0] = R2[0] = L[0] = L2[0] = make_pair(0,0);
  for(i=1;i<=N;i++){
    nowr += S[i-1].second;
    R[i] = make_pair(S[i-1].first,max(R[i-1].second,nowr-S[i-1].first));
    R2[i] = make_pair(S[i-1].first,max(R2[i-1].second,nowr-S[i-1].first*2));
  }
  for(i=1;i<=N;i++){
    nowl += S[N-i].second;
    L[i] = make_pair(C-S[N-i].first,max(L[i-1].second,nowl-(C-S[N-i].first)));
    L2[i] = make_pair(C-S[N-i].first,max(L2[i-1].second,nowl-(C-S[N-i].first)*2));
  }
  ll ans = 0;j = N;
  for(i=0;i<=N;i++){
    while(L2[j].first+R[i].first >= C) j--;
    ans = max(ans,R[i].second+L2[j].second);
  }
  i = N;
  for(j=0;j<=N;j++){
    while(L[j].first+R2[i].first >= C) i--;
    ans = max(ans,R2[i].second+L[j].second);
  }
  printf("%lld\n",ans);
  /*for(i=0;i<=N;i++) printf("%lld %lld|%lld %lld\n",R[i].first,R[i].second,R2[i].first,R2[i].second);
  printf("-----------\n");
  for(i=0;i<=N;i++) printf("%lld %lld|%lld %lld\n",L[i].first,L[i].second,L2[i].first,L2[i].second);*/
}