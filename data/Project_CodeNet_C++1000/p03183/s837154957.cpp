#include <bits/stdc++.h>     // [PRIMES]               1777 ~2^10.80
using namespace std;                     //                       10333 ~2^13.33
using ll=long long;                      // seq 1 128 | factor   100333 ~2^16.61
using vl=vector<ll>;                     //   | grep -v ' .* '  1300111 ~2^20.31
using vvl=vector<vl>;                    //                    10300777 ~2^23.30
using vb=vector<bool>;                   //                   100400999 ~2^26.58
using vs=vector<string>;                 //                  1300400999 ~2^30.28
using pll=pair<ll,ll>;                   //                 10200500333 ~2^33.25
const ll oo =0x3f3f3f3f3f3f3f3fLL;       //                100200400777 ~2^36.54
const double eps=1e-9;                   //               1200300700111 ~2^40.13
#define sz(c) ll((c).size())             //              10200300500777 ~2^43.21
#define all(c) begin(c),end(c)           //             100200300400777 ~2^46.51
#define mp make_pair                     //            1200300400600999 ~2^50.09
#define mt make_tuple                    //           10200300400600111 ~2^53.18
#define pb push_back                     //          100200300400600333 ~2^56.48
#define eb emplace_back                  //         1200300400500800999 ~2^60.06
#define xx first
#define yy second
#define FOR(i,a,b) for(ll i=(a); i<(ll)(b); i++)
#define FORD(i,a,b) for(ll i=ll(b)-1;i>=(a);i--)
#define TR(X) ({if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

vector<pair<pll,ll>> blocks;

vvl dp;
ll f(ll ind, ll wei){
  if(wei < 0) return -1 * oo;
  if(ind >= sz(blocks)) return 0;
  if(dp[ind][wei] != -1) return dp[ind][wei];
  ll base = f(ind+1, wei);
  ll wei_new = wei - blocks[ind].xx.xx;
  wei_new = min(wei_new, blocks[ind].xx.yy);
  ll take = f(ind+1, wei_new) + blocks[ind].yy;
  ll res = max(base, take);
  dp[ind][wei] = res;
  return res;
}

int main(){
  ll N;
  cin >> N;
  dp.resize(N,vl(20005,-1));
  FOR(i,0,N){
    ll w,s,v;
    cin >> w >> s >>v;
    blocks.pb(mp(mp(w,s),v));
  }
  auto cmp = [&] (pair<pll,ll> in, pair<pll,ll> in2) {
    ll s1 = in.xx.xx;
    ll s2 = in2.xx.xx;
    ll w1 = in.xx.yy;
    ll w2 = in2.xx.yy;
    ll op1 = min(s1 - w2, s2);
    ll op2 = min(s2 - w1, s1);
    return op1 > op2;
  };
  sort(all(blocks), cmp);
  cout << f(0, 20004) << endl;
} //cin.tie(0) bei schnellem Wechseln
