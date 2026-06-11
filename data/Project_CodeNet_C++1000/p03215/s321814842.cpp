// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll n,k,max_b=1,ans;
  cin >> n>>k;
  ll a[n],sum[n+1];
  vector<ll> v,tmp;
  sum[0]=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum[i+1] = sum[i]+a[i];
  }
  for(ll i=1;i<sum[n];i<<=1){
    max_b++;
  }
  max_b--;
  for(int i=0;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      v.push_back(sum[j]-sum[i]);
    }
  }
  for(ll i=((ll)1<<max_b);i>=1;i>>=1){
    for(auto j:v){
      if(j&i){
        tmp.push_back(j);
      }
    }
    if(tmp.size()>=k){
      v = move(tmp);
    }
    tmp.clear();
  }
  if(v.size()<k){
    ans = 0;
  }else{
    ans = v[0];
    for(ll i=1;i<v.size();i++){
      ans &= v[i];
    }
  }
  cout << ans << endl;
}

