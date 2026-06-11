#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define rep(i,N) for(int i=0;i<N;i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int A,B,Q;
  cin>>A>>B>>Q;
  vector<ll>s(A),t(B),x(Q);
  for(int i=0;i<A;i++)cin>>s[i];
  for(int i=0;i<B;i++)cin>>t[i];
  for(int i=0;i<Q;i++)cin>>x[i];
  sort(rng(s));
  sort(rng(t));
  for(int i=0;i<Q;i++){
    auto sp=lower_bound(rng(s),x[i]);
    auto tp=lower_bound(rng(t),x[i]);
    ll ans=LONG_MAX;
    //sr->t
    if(sp<s.end()){
      auto p=lower_bound(rng(t),*sp);
      ll D=abs(x[i]-*sp);
      if(p<t.end())ans=min(ans,abs(*sp-*p)+D);
      if(p>t.begin())ans=min(ans,abs(*(p-1)-*sp)+D);
    }
    //sl->t
    if(sp>s.begin()){
      sp--;
      auto p=lower_bound(rng(t),*sp);
      ll D=abs(x[i]-*sp);
      if(p<t.end())ans=min(ans,abs(*sp-*p)+D);
      if(p>t.begin())ans=min(ans,abs(*(p-1)-*sp)+D);
    }
    //tr->s
    if(tp<t.end()){
      auto p=lower_bound(rng(s),*tp);
      ll D=abs(x[i]-*tp);
      if(p<s.end())ans=min(ans,abs(*tp-*p)+D);
      if(p>s.begin())ans=min(ans,abs(*(p-1)-*tp)+D);
    }
    //tl->s
    if(tp>t.begin()){
      tp--;
      auto p=lower_bound(rng(s),*tp);
      ll D=abs(x[i]-*tp);
      if(p<s.end())ans=min(ans,abs(*tp-*p)+D);
      if(p>s.begin())ans=min(ans,abs(*(p-1)-*tp)+D);
    }
    cout<<ans<<endl;
  }
  return 0;
}
