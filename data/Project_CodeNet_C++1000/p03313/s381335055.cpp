#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vll;

#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a) repi(i,0,a)
#define rrep(i,a) for(ll i=a-1;i>=0;i--)

//debug
#define debug(arr) cerr<<#arr<<"(l"<<__LINE__<<") : ";for(auto x:arr)cerr<<x<<" ";cerr<<endl;

void update(ll* f, ll* s, ll val){
  if(val > *f){
    *s = *f;
    *f = val;
  }
  else if(val > *s){
    *s = val;
  }
}

int main(){
  ll N; cin >> N;
  ll A[1 << N];
  rep(i, 1 << N) cin >> A[i];

  vll ans(1, A[0] + A[1]);
  vector<P> or12;
  or12.emplace_back(0, -1);
  if(A[0] > A[1]) or12.emplace_back(0, 1);
  else or12.emplace_back(1, 0);
  repi(n, 2, 1 << N){
    ll f = n, s = 0;
    if(A[s] > A[f]) swap(f, s);
    rep(i, N){
      ll mask = 1 << i;
      if(n & mask){
        if(A[or12[n-mask].first] >  A[f]){
          s = f;
          f = or12[n-mask].first;
          if(A[or12[n-mask].second] > A[s])
            s = or12[n-mask].second;
        }
        else if(A[or12[n-mask].first] >  A[s] && f != or12[n-mask].first){
          s = or12[n-mask].first;
        }
      }
    }
    ans.push_back(max(ans.back(), A[f] + A[s]));
    or12.emplace_back(f, s);
    // printf("%lld : %lld %lld\n", n, f, s);
  }
  for(ll a : ans) cout << a << endl;
  return 0;
}
