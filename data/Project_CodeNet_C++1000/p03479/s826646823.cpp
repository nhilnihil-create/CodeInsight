#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
using ll = long long;
using P = pair<ll,ll>;

int main(){
  ll x,y;
  cin>>x>>y;
  bool ok = true;
  ll sum = 1;
  while(ok){
    if (x*2 <= y){
      sum++;
      x *= 2;
    }
    else {
      ok = false;
    }
  }
  cout << sum << endl;
}