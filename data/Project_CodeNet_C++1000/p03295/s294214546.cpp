#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e15;

int main() {
  ll n,m;
  cin >> n >> m;
  priority_queue<pll,vector<pll>,greater<pll>> q;
  for(ll i=0;i<m;i++) {
    ll a,b;
    cin >> a >> b;
    q.push({b,a});
  }
  ll cnt=0;
  ll id=-1;
  while(q.size()) {
    ll l=q.top().second;
    ll r=q.top().first;
    q.pop();
    if(id<=l) {
      id=r;
      cnt++;
    }
  }
  cout << cnt << endl;
}