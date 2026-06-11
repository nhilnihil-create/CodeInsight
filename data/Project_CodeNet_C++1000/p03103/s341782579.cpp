#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,b) for (ll i=a;i<=ll(b);i++)
using namespace std;
ll ctoi(const char c){if('0'<=c&&c<='9') return (c-'0');return -1;}
#define ALL(x) begin(x),end(x)
  
int main(){
  ll n,m; cin >> n >> m;
  vector<pair<ll,ll>> v;
  rep(i,n){
    ll a,b; cin >> a >> b;
    v.push_back(make_pair(a,b));
  }
  sort(ALL(v));
  
  ll purchaseNum = m;
  ll sum = 0;
  rep(i,n){
    if(purchaseNum>=v[i].second) sum += v[i].first*v[i].second;
    else sum += v[i].first*purchaseNum;
    purchaseNum -= v[i].second;
    if(purchaseNum<=0) break;
  }
  cout << sum << endl;
} 