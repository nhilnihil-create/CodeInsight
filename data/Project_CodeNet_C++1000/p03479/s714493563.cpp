#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
  ll x,y,ans=0;
  cin >> x>>y;
  while(y>=x){
    x*=2;
    ans++;
  }
  cout << ans <<endl;
}
