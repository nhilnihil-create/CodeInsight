#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
  ll n;
  cin >> n;
  vector<ll> even(100010, 0), odd(100010, 0);
  bool flag = true;
  ll ev = 0, ov = 0;
  rep(i, 0, n){
    ll t; cin >> t;
    if(i%2 == 0){
      even[t]++;
      if(even[t] > even[ev]) ev = t;
    }else{
      odd[t]++;
      if(odd[t] > odd[ov]) ov = t;
    }
  }
  sort(even.begin(),even.end(),greater<ll>());
  sort(odd.begin(),odd.end(),greater<ll>());
  if(ev == ov){
    cout << n - max(even[0]+odd[1],even[1]+odd[0]) << endl;
  }else{
    cout << n - even[0] - odd[0] << endl;
  }
  return 0;
}