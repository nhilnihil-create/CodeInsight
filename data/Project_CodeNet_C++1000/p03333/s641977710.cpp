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
  ll n,x=0,ans=0;
  cin >> n;
  vector<ll> l(n),r(n);
  vector<TP> lr(n),rl(n);
  vector<bool> used(n,false);
  for(int i=0;i<n;i++){
    cin >> l[i] >> r[i];
    lr[i] = TP(l[i],r[i],i);
    rl[i] = TP(r[i],l[i],i);
  }
  ll lridx=0,rlidx=0,tmp=0;
  sort(lr.begin(),lr.end(),greater<>());
  sort(rl.begin(),rl.end());
  for(int i=0;i<n;i++){
    if(i%2==0){
      while(used[get<2>(rl[rlidx])]){
        rlidx++;
      }
      used[get<2>(rl[rlidx])] = true;
      ll le = get<1>(rl[rlidx]);
      ll ri = get<0>(rl[rlidx]);
      if(x<le){
        ans += le-x;
        x = le;
      }else if(x>ri){
        ans += x-ri;
        x = ri;
      }
    }else{
      while(used[get<2>(lr[lridx])]){
        lridx++;
      }
      used[get<2>(lr[lridx])] = true;
      ll le = get<0>(lr[lridx]);
      ll ri = get<1>(lr[lridx]);
      if(x<le){
        ans += le-x;
        x = le;
      }else if(x>ri){
        ans += x-ri;
        x = ri;
      }
    }
  }
  ans += abs(x);
  fill(used.begin(),used.end(),false);
  lridx = 0;
  rlidx = 0;
  x = 0;
  for(int i=0;i<n;i++){
    if(i%2){
      while(used[get<2>(rl[rlidx])]){
        rlidx++;
      }
      used[get<2>(rl[rlidx])] = true;
      ll le = get<1>(rl[rlidx]);
      ll ri = get<0>(rl[rlidx]);
      if(x<le){
        tmp += le-x;
        x = le;
      }else if(x>ri){
        tmp += x-ri;
        x = ri;
      }
    }else{
      while(used[get<2>(lr[lridx])]){
        lridx++;
      }
      used[get<2>(lr[lridx])] = true;
      ll le = get<0>(lr[lridx]);
      ll ri = get<1>(lr[lridx]);
      if(x<le){
        tmp += le-x;
        x = le;
      }else if(x>ri){
        tmp += x-ri;
        x = ri;
      }
    }
  }
  tmp += abs(x);
  ans = max(ans,tmp);
  cout << ans << endl;
}
