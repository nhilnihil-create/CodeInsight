#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  ll n,a,b,c,d,e; cin >>n >>a >>b >>c >>d >>e;
  ll m = min(a,min(b,min(c,min(d,e))));
  cout << 4+(n+m-1)/m << endl;
  return 0;
}