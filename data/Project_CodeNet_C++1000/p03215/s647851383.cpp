#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n,k,a[1009], cumsum[1009], cnt[42];
  map<long long, long long> mp;
  cin >> n >> k;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  cumsum[0] = 0;
  for(int i=1;i<=n;i++){
    cumsum[i] = cumsum[i-1] + a[i-1];
  }
  for(int i=0;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      mp[cumsum[j] - cumsum[i]]++;
    }
  }
  for(auto p: mp){
    for(int j=0;j<=40;j++){
      if((p.first>>j)&1)cnt[j]+=p.second;
    }
  }
  long long ans=0;
  long long keta=40;
  while(cnt[keta]<k)keta--;
  ans += 1LL<<keta;
  keta--;
  while(keta>=0){
    long long c=0;
    for(auto p: mp){
      if(((ans&p.first)==ans)&&(((p.first>>keta)&1)==1))c+=p.second;
    }
    if(c>=k){
      ans+=1LL<<keta;
    }
    keta--;
  }
  cout << ans << endl;
}
