#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

ll comb(ll n, ll r) {
    ll ret = 1;
    for (ll i = 0; i < r; i++) ret = ret * (n - i);
    for (ll i = 1; i <= r; i++) ret = ret / i;
    return ret;
}

int main(){
   ll n; cin >> n;
   vector<ll> a(n);
   vector<ll> sum(n+1,0);
   ll ans = 0, count = 0, mem = 0;

   rep(i,n) cin >> a[i];

   sum[0] = 0;
   rep(i,n) sum[i+1] = sum[i] + a[i];

   sort(sum.begin(),sum.end());

   mem = -1;

   rep(i,n+1){
        if(mem == sum[i]){
            count ++;
        }else{
            if(count >= 2) ans += comb(count,2);
            count = 1;
            mem = sum[i];
        }
   }

    if(count >= 2) ans += comb(count,2);

    cout << ans;



}