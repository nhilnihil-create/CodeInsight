#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int main(){
  int k;cin >> k;
  vector<int> a(k);
  rep(i,k) cin >> a[i];
  if(a[k-1]!= 2){
    cout << -1 << endl;
    return 0;
  }
  //cout << k << endl;
  ll mx = 1e16;
  ll mi = 1;
  ll mid = (mx+mi)/2;
  ll temp;
  while(mx-mi>1){
    temp = (mx+mi)/2;
    //cout << temp << endl;
    rep(i,k){
      temp = temp/a[i]*a[i];
      if(temp == 0) {
        mi = (mx+mi)/2; 
        break;
      }
    }
    //cout << " " << temp << endl;
    if(temp > 2) mx = (mx+mi)/2;
    if(temp == 2) {
      mid = (mx+mi)/2;
      break;
    }
  }
  if(mid > 1e15) {
    cout << -1 << endl;
    return 0;
  }
  //cout << mid << endl;
  //cout << temp << endl;
  mx = mid;
  mi = 1;
  while(mx-mi>1){
    temp = (mx+mi)/2;
    rep(i,k){
      temp = temp/a[i]*a[i];
      if(temp == 0) {
        mi = (mx+mi)/2; 
        break;
      }
    }
    if(temp == 2) mx = (mx+mi)/2;
  }

  ll mians = mx;

  mx = 1e16;
  mi = mid;
  while(mx-mi>1){
    temp = (mx+mi)/2;
    rep(i,k) temp = temp/a[i]*a[i];
    if(temp > 2) mx = (mx+mi)/2;
    if(temp == 2) mi = (mx+mi)/2;
  }

  ll mxans = mi;
  printf("%lld %lld\n",mians,mxans);
}