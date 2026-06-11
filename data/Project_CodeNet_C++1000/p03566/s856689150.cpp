// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
}
signed main(){
  init_io();
  ll n,sum_t=0;
  double ans=0,pre_v=0,now_v;
  cin >> n;
  vector<ll> t(n+1),v(n+1);
  t[0] = v[0] = 0;
  for(int i=1;i<n+1;i++){
    cin >> t[i];
    t[i]*=2;
    sum_t+=t[i];
  }
  vector<ll> v_limit(sum_t+1);
  for(int i=1;i<=n;i++){
    t[i]+=t[i-1];
  }
  for(int i=1;i<n+1;i++){
    cin >> v[i];
    v[i] *= 2;
  }
  for(int j=sum_t;j>=0;j--){
    v_limit[j] = sum_t-j;
  }
  v_limit[0]=0;
  for(int i=1;i<=n;i++){
    for(int j=t[i];j>=0;j--){
      if(j>=t[i-1]){
        v_limit[j] = min(v_limit[j],v[i]);
      }else{
        v_limit[j] = min(v_limit[j],v[i]+(t[i-1]-j));
      }
    }
  }
  for(int i=1;i<=sum_t;i++){
    now_v = pre_v;
    if(now_v<v_limit[i]){
      now_v++;
    }else if(now_v>v_limit[i]){
      now_v--;
    }
    ans += pre_v + (now_v-pre_v)/2;
    pre_v = now_v;
  }
  cout << ans/4 << endl;
}
