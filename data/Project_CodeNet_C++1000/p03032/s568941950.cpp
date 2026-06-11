#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
ll mod = 1000000007;

int main(){
  ll n,k; cin >> n >> k;
  vector<ll> v(n+1,0);
  rep(i,n){
    cin >> v[i];
  }
  ll ans = 0;
  rep(a,n+1)rep(b,n+1){
    if(a+b>n||a+b>k)continue;
    ll sum=0;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    rep(i,a){
      sum+=v[i];
      if(v[i]<0)q.push(v[i]);
    }
    rep(i,b){
      sum+=v[n-i-1];
      if(v[n-i-1]<0)q.push(v[n-i-1]);
    }
    ll num = max((ll)0, k-a-b);
    rep(i,num){
      if(q.empty()) break;
      ll t = q.top(); q.pop();
      sum-=t;
    }
    ans = max(ans,sum);
  }
  cout << ans;
  return 0;
}