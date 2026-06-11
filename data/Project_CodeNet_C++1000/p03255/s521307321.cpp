#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

const ll INF = 1e16;

int main() {
    ll n, x;
    cin >> n >> x;
    VL a(n);
    REP(i,n) a[i] = lin();

    reverse(ALL(a));
    VL sum(n+1);
    REP(i,n) sum[i+1] = sum[i] + a[i];

    ll mi = INF;
    VL cnt(n+1);
    FOR(t,1,n) cnt[t] = t * x;
    FOR(t,1,n){
        int r = 2 * t;
        if (r > n) r = n;
        cnt[t] += 5 * sum[r];
    }

    FOR(i,3,n){
        FOR(t,1,n){
            int l = (i - 1) * t, r = i * t;
            if (l > n) break;
            if (r > n) r = n;
            cnt[t] += (2 * i + 1) * (sum[r] - sum[l]);
            if (cnt[t] > INF || cnt[t] < 0) cnt[t] = INF;
        }
    }

    FOR(t,1,n) mi = min(mi, cnt[t]);

    ll ans = mi + n * x;
    cout << ans << endl;

    return 0;
}
