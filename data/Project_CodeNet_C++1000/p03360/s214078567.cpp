#include<bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vl = vector<ll>;

int main() {
  ll a, b, c, k;
  cin >> a >> b >> c >> k;
  ll x = a + b + c * pow(2,k);
  ll y = a + b * pow(2,k) + c;
  ll z = a * pow(2,k) + b + c;
  cout << max(max(x,y),z) << endl;
}