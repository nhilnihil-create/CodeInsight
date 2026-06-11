#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
ll n,x;
cin >> n >> x;
vector<ll> a(n);
rep(i,n) cin >> a.at(i);
vector<ll> b(n);
rep(i,n)b.at(i) = abs(a.at(i)-x);
ll ans;
rep(i,n-1){
  if(i == 0) ans = gcd(b.at(i),b.at(i+1));
  else ans = gcd(ans,b.at(i));
}
  if(n==1)ans = b.at(0);
cout << ans << endl;
}
