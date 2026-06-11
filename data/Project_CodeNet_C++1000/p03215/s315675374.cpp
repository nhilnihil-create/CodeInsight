#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

ll bpow(ll a , ll b){
  if (b == 0) return 1;
  ll ret;
  if (b%2 == 0){
    ll  t = bpow(a, b/2);
    ret = t*t;
  }else{
    ll t = bpow(a, (b-1)/2);
    ret = a*t*t;
  }
  return ret;
}
int main(){
  ll N, K; cin >> N >> K;
  vector<ll> sum(N+1,0);
  REP(i,N){
    ll a; cin >> a;
    sum[i+1] = sum[i] + a;
  }
  multiset<ll> cand;
  FOR(l,1,N+1) FOR(r,l,N+1){
    cand.insert(sum[r]-sum[l-1]);
  }
  //桁数の最大値
  ll M = ceil(log2(sum[N]));
  ll ans = 0;
  IREP(i,M){
    ll t = ans + bpow(2,i);
    ll c = 0;
    auto it = cand.begin();
    while(it!=cand.end()){
      if(t == (t&(*it))) c++;
      it++;
    }
    if(c>=K) ans = t;
  }
  cout << ans << endl;
}