#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, x, y) for(int i = int(x); i < int(y); i++)
#define MAXD 40
#define sf scanf

int n; ll k;
ll cnt[MAXD + 10];

void process(ll x){
    FOR(i, 0, MAXD + 1){
        if(x & (1LL<<i)) cnt[i]++;
    }
}

ll DP[MAXD + 10][2];

ll solve(int pos, int smaller){
    if(pos<0) return 0;
    auto &ret = DP[pos][smaller];
    if(~ret) return ret; ret = 0;
    int cur = ((k>>pos)&1);
    int lim = smaller? 1 : cur;
    FOR(i, 0, lim+1){
        ll now = i ? n - cnt[pos] : cnt[pos];
        ret = max(ret, solve(pos-1, smaller | i < cur) + now * (1LL<<pos));
    }
    return ret;
}

int main(){
    #ifdef VAMP
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // VAMP
    memset(DP, -1, sizeof(DP));
    sf("%d %lld", &n, &k);
    FOR(i, 0, n){
        ll x; sf("%lld", &x);
        process(x);
    }
    printf("%lld\n", solve(40, 0));
    return 0;
}
