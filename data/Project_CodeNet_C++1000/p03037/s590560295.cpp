#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
#define ll long long
#define ld long double
ll ctoi(const char c){if('0'<=c&&c<='9') return (c-'0');return -1;}
#define ALL(x) begin(x),end(x)
  
int main(){
  ll n,m;
  cin >> n >> m;
  vector<ll> l(m),r(m);
  rep(i,m) cin >> l[i] >> r[i];
  sort(ALL(l));
  sort(ALL(r));
  if(r[0]-l[m-1]+1>0) cout << r[0]-l[m-1]+1 << endl;
  else cout << "0" << endl;
}