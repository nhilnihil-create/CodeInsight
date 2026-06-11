#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int main(){
  ll N,M; cin >> N >> M;
  priority_queue<pll> pque;
  for(ll i=0;i<N;i++){
    ll a; cin >> a;
    pque.push(make_pair(a,1));
  }
  for(ll i=0;i<M;i++){
    ll b,c; cin >> b >> c;
    pque.push(make_pair(c,b));
  }
  ll cnt = 0;
  ll ans = 0;
  while(cnt<=N){
    pll p = pque.top(); pque.pop();
    if(cnt+p.second<=N){
      cnt += p.second;
      ans += p.second*p.first;
      continue;
    }else{
      ans += p.first*(N-cnt);
      break;
    }
  }
  cout << ans << endl;
}
