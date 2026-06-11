#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll a,b,k;
  cin >> a >> b >> k;
  map<ll,ll> cnt;
  for(ll i=a;i<=min(a+k-1,b);i++) cnt[i]++;
  for(ll i=b;i>=max(b-k+1,a);i--) cnt[i]++;
  for(auto p:cnt) cout << p.first << endl;
}