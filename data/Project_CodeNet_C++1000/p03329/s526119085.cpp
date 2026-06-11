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


vector<ll> dp(100010,-1);

ll rec(ll n){


    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];

    ll Min = MAX;

    for(int i = 1; i <= n; i *= 6) Min = min(Min,rec(n-i)+1);
    for(int i = 1; i <= n; i *= 9) Min = min(Min,rec(n-i)+1);

    return dp[n] = Min;
}

int main() {

    ll n; cin >> n;

    rec(n+1);

    cout << dp[n];

}
