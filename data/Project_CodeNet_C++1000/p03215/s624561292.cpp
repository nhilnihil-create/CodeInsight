// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n;cin >> n;
    int k;cin >> k;
    vector<LL> a(n);
    inc(i, 0, n) cin >> a[i];
    vector<LL> v, aa(n+1);
    aa[0] = 0;
    inc(i, 0, n){
        aa[i+1] = aa[i] + a[i];
    }
    inc(i, 0, n){
        inc(j, i, n){
            v.pb(aa[j+1]-aa[i]);
        }
    }

    dec(i, 0, 64){
        vector<LL> tmp;
        for(auto vv : v) {
            if(vv & (1LL << i)){
                tmp.pb(vv);
            }
        }
        if(tmp.size() < k) continue;
        v = tmp;
    }

    LL ans = v[0];
    for(auto vv : v) {
        ans &= vv;
    }

    cout << ans << endl;
    return 0;
}
