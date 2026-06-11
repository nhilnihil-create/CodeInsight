#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main(){
  ll n;
  cin >> n;
  vector<ll>time(13);
  vector<bool>ampm(24,false);
  time[0]++;
  ampm[0]=true;
  ampm[24]=true;
  for(int i=0; i<n; i++){
    ll d;
    cin >> d;
    time[d]++;
    if(time[d]>2){
      cout << 0 << endl;
      return 0;
    }
    if(d==12 && time[d]>1){
      cout << 0 << endl;
      return 0;
    }
    if(d==0 && time[d]>1){
      cout << 0 << endl;
      return 0;
    }
  }
  if(time[12]==1) ampm[12]=true;
  for(int i=1; i<12; i++){
    if(time[i]==2){
      ampm[i]=true;
      ampm[24-i]=true;
    }
  }
  
  ll ans=0;
  for(ll i=0; i< 1<<11; i++){
    ll x = i;
    ll count=0;
    for(int j=0; j<12; j++){
      count++;
      if(time[count]==2 || time[count]==0)continue;
      if(i>>j & 1){
        ampm[count]=true;
        ampm[24-count]=false;
      }
      else{
        ampm[count]=false;
        ampm[24-count]=true;
      }
    }
      
    ll MIN = 10e6;
    ll count2=1;
    for(int i=1; i<=24; i++){
      if(ampm[i]){
        MIN=min(MIN,count2);
        //cout << i << " " << count2 << endl;
        count2=0;
      }
      count2++;
    }
    ans = max(ans,MIN);
  }
  cout << ans << endl;
  
}
  
  
  
  
