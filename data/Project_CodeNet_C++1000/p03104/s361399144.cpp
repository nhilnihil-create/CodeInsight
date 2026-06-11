#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

ll res(ll x){
  if(x%4==0) return x;
  if(x%4==1) return 1;
  if(x%4==2) return x+1;
  if(x%4==3) return 0;
}
int main() {
  ll a,b;
  cin >> a >> b;
  ll ansa=0,ansb=0;;
  ll now=1;
  a--;
  ansa=res(a);
  ansb=res(b);
  ll ans=ansa^ansb;
  cout << ans << endl;
}