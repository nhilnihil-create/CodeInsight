#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll a,b;
  cin >> a >> b;
  if(a==b+1){
    ll ans=a^b;
    cout << ans << endl;
    return 0;
  }
  if(a==b){
    cout << a << endl;
    return 0;
  }

  ll ans;

  if(a%2==0){
    ll cnt=0;
    if(b%2==0){
      ll tmp=b-a;
      cnt=tmp/2;
      cnt=cnt%2;
      ans=cnt^b;
      cout << ans << endl;
    }else{
      ll tmp=b+1-a;
      cnt=tmp/2;
      cnt=cnt%2;
      cout << cnt << endl;
    }
  }else{
    ll cnt=0;
    ll tmp=0;
    if(b%2==0){
      tmp=b-a-1;
      cnt=tmp/2;
      cnt%=2;
      ans=a^b^cnt;
      cout << ans << endl;
    }else{
      tmp=b-a;
      cnt=tmp/2;
      cnt%=2;
      ans=a^cnt;
      cout << ans << endl;
    }
  }
  return 0;
}
