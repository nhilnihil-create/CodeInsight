#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  ll x,y; cin >> x >> y;

  ll mul = 2;
  ll c = x;
  ll ans = 0;
  while(1){
    ans++;
    c *= mul;
    if(c>y) break;
  }

  cout << ans << endl;
  
  return 0;
}
