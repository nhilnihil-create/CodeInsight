#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {

    ll n; cin >> n;
    string s; cin >> s;
    ll ans = 1;
    ll sum = 0;
    vector<ll> c(26,1);
    rep(i,n){
        c[(int)(s[i]-'a')] ++;
    }
    rep(i,26){
        ans = (ans*c[i])%1000000007;
    }
    ans --;
    cout << ans;
    return 0;
}
