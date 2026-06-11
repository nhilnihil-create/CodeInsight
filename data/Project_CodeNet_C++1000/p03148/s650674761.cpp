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
  ll n,k;
  cin >> n >> k;
  priority_queue<pll> q;
  for(ll i=0;i<n;i++) {
    ll t,d;
    cin >> t >> d;
    q.push(pll(d,t));
  }
  priority_queue<pll,vector<pll>,greater<pll>> q1;
  map<ll,ll> ans;
  map<ll,ll> cnt;
  ll kind=0;
  ll sum=0;
  for(ll i=0;i<k;i++) {
    ll d=q.top().first;
    ll t=q.top().second;
    q.pop();
    sum+=d;
    q1.push(pll(d,t));
    if(cnt[t]==0) {
      kind++;
    }
    cnt[t]++;
  }
  ans[kind]=sum+kind*kind;
  while(q.size()&&q1.size()) {
    ll d=q.top().first;
    ll t=q.top().second;
    q.pop();
    if(cnt[t]) continue;
    cnt[t]++;
    ll f=0;
    sum+=d;
    kind++;
    while(q1.size()) {
      ll d1=q1.top().first;
      ll t1=q1.top().second;
      q1.pop();
      if(cnt[t1]==1) continue;
      cnt[t1]--;
      f=1;
      sum-=d1;
      break;
    }
    if(f) {
      ans[kind]=sum+kind*kind;
    }
  }
  ll res=0;
  for(auto p:ans) {
    res=max(p.second,res);
  }
  cout << res << endl;
}