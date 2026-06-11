#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;

signed main(){

  int n;
  cin>>n;
  vector<ll> a(n);
  for(auto& ai:a)cin>>ai;

  vector<ll> power(60);
  for(int i=0;i<60;++i)power[i] = (1LL<<i);
  map<ll,ll> cnt;
  for(auto& ai:a)cnt[ai]++;
  sort(a.begin(),a.end(),greater<>());
  int ans = 0;
  for(int i=0;i<n;++i){
    for(int j=0;j<60;++j){
      if(cnt.count(power[j]-a[i])==0)continue;
      if(power[j]-a[i]==a[i]){
        if(cnt[a[i]]>=2){
          cnt[a[i]]-=2;
          ans++;
        }
      }
      else if(cnt[power[j]-a[i]]>=1&&cnt[a[i]]>=1){
        cnt[power[j]-a[i]]--;
        cnt[a[i]]--;
        ans++;
      }
    }
  }
  cout<<(ans)<<endl;

}