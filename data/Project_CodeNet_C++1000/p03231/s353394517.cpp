#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T&a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T&a,T b){if(a>b){a=b;return 1;}return 0;}
typedef long long ll;

ll n,m,k;
string s,t;

int main() {
  cin >> n >> m >> s >> t;
  ll g=__gcd(n,m);
  ll ans=n/g*m; n/=g,m/=g;
  bool ok=true;
  rep(i,g)if(s[n*i]!=t[m*i]) ok=false;
  cout << (ok ? ans : -1) << endl;
}