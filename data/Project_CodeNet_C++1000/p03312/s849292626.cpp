#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;

#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a) repi(i,0,a)
#define rrep(i,a) for(ll i=a-1;i>=0;i--)

//debug
#define debug(arr) cerr<<#arr<<"(l"<<__LINE__<<") : ";for(auto x:arr)cerr<<x<<" ";cerr<<endl;

int main(){
  ll N; cin >> N;
  ll A[N];
  rep(i, N) cin >> A[i];

  ll sumf[N] = {A[0]};
  ll sumb[N] = {A[N-1]};
  rep(i, N-1) sumf[i+1] = A[i+1] + sumf[i];
  rep(i, N-1) sumb[i+1] = A[N-i-2] + sumb[i];

  ll ans = sumf[N-1];
  repi(nbc, 2, N-1){
    ll nb, nd;
    ll halfbc = lower_bound(sumf, sumf + nbc, sumf[nbc-1] / 2) - sumf;
    if(halfbc == 0) nb = 1;
    else if(sumf[nbc-1] / 2 - sumf[halfbc-1] < sumf[halfbc] - sumf[nbc-1] / 2)
      nb = halfbc;
    else nb = halfbc + 1;

    ll halfde = lower_bound(sumb, sumb + N - nbc, sumb[N-nbc-1] / 2) - sumb;
    if(halfde == 0) nd = 1;
    else if(sumb[N-nbc-1] / 2 - sumb[halfde-1] < sumb[halfde] - sumb[N-nbc-1] / 2)
      nd = halfde;
    else nd = halfde + 1;

    ll P = sumf[nb-1], Q = sumf[nbc-1] - sumf[nb-1];
    ll R = sumb[nd-1], S = sumb[N-nbc-1] - sumb[nd-1];
    ll diff = max(max(P, Q), max(R, S)) - min(min(P, Q), min(R, S));
    ans = min(diff, ans);
    // printf("%lld %lld %lld %lld\n", P, Q, R, S);
  }
  cout << ans << endl;
  return 0;
}
