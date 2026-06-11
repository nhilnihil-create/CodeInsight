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
void calc(const vector<ll> &a,vector<ll> &mi,vector<ll> &ma){
  ll tsum=0,idx=1,asum=0;
  ll n = a.size();
  asum=a[0];
  tsum=a[0];
  for(int i=1;i<n;i++){
    asum += a[i];
    while(idx<i){
      ll nt = tsum+a[idx];
      ll now = abs(asum-2*tsum);
      ll nxt = abs(asum-2*nt);
      if(now>nxt){
        tsum += a[idx];
        idx++;
      }else{
        break;
      }
    }
    mi[i] = min(tsum,asum-tsum);
    ma[i] = max(tsum,asum-tsum);
  }
}
signed main(){
  init_io();
  ll n;
  ll ans=1e18;
  cin >> n;
  vector<ll> a(n),sum(n,0);
  vector<ll> lvmin(n),rvmin(n);
  vector<ll> lvmax(n),rvmax(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  calc(a,lvmin,lvmax);
  reverse(a.begin(),a.end());
  calc(a,rvmin,rvmax);
  for(int i=1;i+2<n;i++){
    //cout << i<<" "<<lvmin[i]<<" "<<lvmax[i]<<" "<<rvmin[n-2-i]<<" "<<rvmax[n-2-i]<<endl;
    ans = min(ans,-min(lvmin[i],rvmin[n-2-i])+max(lvmax[i],rvmax[n-2-i]));
  }
  cout << ans << endl;
}
