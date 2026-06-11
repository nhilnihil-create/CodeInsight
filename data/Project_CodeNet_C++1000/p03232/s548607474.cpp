#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<int, int> P;
#define REP(i, x, n) for(lint i = x ; i < n ; i++)
#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for(lint i = n - 1 ; i >= 0 ; i--)
#define SORT(c) sort((c).begin(), (c).end())

const int IINF = 1e9 + 10;
const lint LLINF = (lint)1e18 + 10;
const lint MOD = (lint)1e9 + 7;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

lint power(lint x, lint n){
    lint res = 1;
    while(n > 0){
        if(n & 1){
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        n >>= 1;
    }
    return res;
}

int main(){
    lint n;
    cin >> n;
    vector<lint> a(n);
    rep(i, n){
        cin >> a[i];
    }
    lint fact = 1;
    REP(i, 1, n+1){
        fact *= i;
        fact %= MOD;
    }
    vector<lint> p(n+1);
    p[0] = 0;
    REP(i, 1, n+1){
        p[i] = power(i, MOD-2);
        p[i] += p[i-1];
        p[i] %= MOD;
    }
    lint ans = 0;
    rep(i, n){
        ans += a[i] * ((p[n-i] + p[i+1] - 1) % MOD);
        ans %= MOD;
    }
    ans *= fact;
    ans %= MOD;
    cout << ans << endl;
    return 0;
}