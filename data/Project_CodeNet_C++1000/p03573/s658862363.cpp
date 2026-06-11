#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  
  if(a!=b&&a!=c)
    cout << a << endl;
  if(b!=a&&b!=c)
    cout << b << endl;
  if(c!=b&&c!=a)
    cout << c << endl;
}