#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  // J100           J600
  //          T400           T900 T1000
  //  S150              S799 S899      S2000
  //RR,RL、LR、LLの4つの進みかたのどれか。全部調べてもよさそう
  //JR,TRとTR,JRで違うから8通りか
  //8*10^5ならなんとかなるか
  ll A,B,Q;
  cin>>A>>B>>Q;
  vector<ll> J(A,0), T(B,0), S(Q,0), ans(Q,1e11);
  for(int i=0; i<A; i++){
    ll s;
    cin>>s;
    J[i]=s;
  }
  for(int i=0; i<B; i++){
    ll t;
    cin>>t;
    T[i]=t;
  }
  for(int i=0; i<Q; i++){
    ll x;
    cin>>x;
    S[i]=x;
  }
  //下準備
  vector<ll> JL(Q,0), TL(Q,0);
  for(int i=0; i<Q; i++){
    ll jl=lower_bound(J.begin(), J.end(), S[i])-J.begin();
    ll tl=lower_bound(T.begin(), T.end(), S[i])-T.begin();
    JL[i]=jl;
    TL[i]=tl;
  }
  //神社R→寺Rパターン
  for(int i=0; i<Q; i++){
    ll now=S[i], tmp=0;
    if(JL[i]==A)
      continue;
    tmp+=abs(now-J[JL[i]]);
    now=J[JL[i]];
    ll tl=lower_bound(T.begin(), T.end(), now)-T.begin();
    if(tl==B)
      continue;
    tmp+=abs(now-T[tl]);
    ans[i]=min(ans[i],tmp);
  }
  //神社R→寺Lパターン
  for(int i=0; i<Q; i++){
    ll now=S[i], tmp=0;
    if(JL[i]==A)
      continue;
    tmp+=abs(now-J[JL[i]]);
    now=J[JL[i]];
    ll tl=lower_bound(T.begin(), T.end(), now)-T.begin();
    if(tl==0)
      continue;
    tmp+=abs(now-T[tl-1]);
    ans[i]=min(ans[i],tmp);
  }
  //神社L→寺Rパターン
  for(int i=0; i<Q; i++){
    ll now=S[i], tmp=0;
    if(JL[i]==0)
      continue;
    tmp+=abs(now-J[JL[i]-1]);
    now=J[JL[i]-1];
    ll tl=lower_bound(T.begin(), T.end(), now)-T.begin();
    if(tl==B)
      continue;
    tmp+=abs(now-T[tl]);
    ans[i]=min(ans[i],tmp);
  }
  //神社L→寺Lパターン  
  for(int i=0; i<Q; i++){
    ll now=S[i], tmp=0;
    if(JL[i]==0)
      continue;
    tmp+=abs(now-J[JL[i]-1]);
    now=J[JL[i]-1];
    ll tl=lower_bound(T.begin(), T.end(), now)-T.begin();
    if(tl==0)
      continue;
    tmp+=abs(now-T[tl-1]);
    ans[i]=min(ans[i],tmp);
  }
  
  //寺R→神社Rパターン
  for(int i=0; i<Q; i++){
    ll now=S[i], tmp=0;
    if(TL[i]==B)
      continue;
    tmp+=abs(now-T[TL[i]]);
    now=T[TL[i]];
    ll jl=lower_bound(J.begin(), J.end(), now)-J.begin();
    if(jl==A)
      continue;
    tmp+=abs(now-J[jl]);
    ans[i]=min(ans[i],tmp);
  }
  //寺R→神社Lパターン
  for(int i=0; i<Q; i++){
    ll now=S[i], tmp=0;
    if(TL[i]==B)
      continue;
    tmp+=abs(now-T[TL[i]]);
    now=T[TL[i]];
    ll jl=lower_bound(J.begin(), J.end(), now)-J.begin();
    if(jl==0)
      continue;
    tmp+=abs(now-J[jl-1]);
    ans[i]=min(ans[i],tmp);
  }
  //寺L→神社Rパターン
  for(int i=0; i<Q; i++){
    ll now=S[i], tmp=0;
    if(TL[i]==0)
      continue;
    tmp+=abs(now-T[TL[i]-1]);
    now=T[TL[i]-1];
    ll jl=lower_bound(J.begin(), J.end(), now)-J.begin();
    if(jl==A)
      continue;
    tmp+=abs(now-J[jl]);
    ans[i]=min(ans[i],tmp);
  }
  //寺L→神社Lパターン
  for(int i=0; i<Q; i++){
    ll now=S[i], tmp=0;
    if(TL[i]==0)
      continue;
    tmp+=abs(now-T[TL[i]-1]);
    now=T[TL[i]-1];
    ll jl=lower_bound(J.begin(), J.end(), now)-J.begin();
    if(jl==0)
      continue;
    tmp+=abs(now-J[jl-1]);
    ans[i]=min(ans[i],tmp);
  }
  for(int i=0; i<Q; i++)
    cout<<ans[i]<<endl; 
}
