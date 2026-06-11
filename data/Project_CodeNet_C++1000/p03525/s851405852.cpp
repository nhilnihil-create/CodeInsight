#include<iostream>
using namespace std;
typedef long long ll;
bool is_zero=false;
ll dcnt[13]={},s=0,man[24];
void calc(ll t){
  if(is_zero) return;
  if(t==13){
    ll tmp=1000;
    for(ll i=0;i<24;i++){
      for(ll j=i+1;j<24;j++){
        if(man[i]&&man[j]){
          tmp=min(tmp,min(j-i,24-(j-i)));
        }
      }
    }
    s=max(tmp,s);
    return;
  }
  if(dcnt[t]>=3){
    is_zero=true;
    s=0;
    return;
  }
  if(t==0||t==12){
    if(dcnt[t]>=2){
      is_zero=true;
      s=0;
    }else if(dcnt[t]>=1){
      man[t]=1;
      calc(t+1);
    }else{
      calc(t+1);
    }
    return;
  }
  if(dcnt[t]>=2){
    man[t]=1;
    man[24-t]=1;
    calc(t+1);
    man[t]=0;
    man[24-t]=0;
  }else if(dcnt[t]>=1){
    man[t]=1;
    calc(t+1);
    man[t]=0;
    man[24-t]=1;
    calc(t+1);
    man[24-t]=0;
  }else{
    calc(t+1);
  }
}
signed main(){
  ll n;
  cin >> n;
  ll d[n];
  dcnt[0]++;
  for(int i=0;i<n;i++){
    cin >> d[i];
    dcnt[d[i]]++;
  }
  calc(0);
  cout << s << endl;
}
