#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define int ll
int cnt[100005]={0};
signed main(){
  ll n,k;
  cin>>n>>k;
  vector<P> vec;
  for(int i=0;i<n;i++){
    ll t,d;
    cin>>t>>d;
    vec.push_back(P(d,t));
  }
  sort(vec.begin(),vec.end(),greater<P>());
  ll ans=0;
  ll val=0;
  for(int i=0;i<k;i++) {
    if(cnt[vec[i].second]==0) val++;
    cnt[vec[i].second]++;
    ans+=vec[i].first;
  }
  ans+=val*val;

  ll nxt_ans=ans;
  ll over=k-1,under=k;
  while(1){
    while(under<n&&cnt[vec[under].second]!=0) under++;
    while(over>=0&&cnt[vec[over].second]<=1) over--;
    if(under>=n||over<0) break;
    cnt[vec[under].second]++;
    cnt[vec[over].second]--;
    ll kans=nxt_ans;
    kans-=vec[over].first;
    kans-=val*val;
    val++;
    kans+=vec[under].first;
    kans+=val*val;
    ans=max(ans,kans);
    nxt_ans=kans;
    over--;
    under++;
  }
  cout<<max(nxt_ans,ans)<<endl;
}
