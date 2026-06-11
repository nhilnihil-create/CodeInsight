// Solid <candgenesis>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
using namespace std;
const ll N = 1e6 + 4;
const ll inf = 1e9 + 7;
const ll inc = 3e5;
typedef pair<ll,ll> LL;

ll n,a[N],i,bit[N],d[N],total,maxx;
void upd(ll p,ll val){
    for (ll i = p;i < N;i += i & -i) bit[i] += val;
}
ll Get(ll p){
    ll res = 0;
    for (ll i = p;i > 0;i -= i & -i) res += bit[i];
    return res;
}
ll cal(ll m){
    ll cnt = 0;
    memset(bit,0,sizeof(bit)); memset(d,0,sizeof(d));
    upd(inc,1);
    for (i = 1;i <= n;i++){
        d[i] = d[i - 1];
        if (a[i] >= m) d[i]++;
        ll p = 2*d[i] - i + inc;
        cnt += Get(p); upd(p,1);
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define task "tst"
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin>>n; total = n*(n + 1)/2; total = ceil((ld)total/2);
    for (i = 1;i <= n;i++) cin>>a[i],maxx = max(a[i],maxx);
    ll l,m,h;
    l = 1; h = maxx;
    //cout<<cal(10); return 0;
    while(l <= h){
        m = (l + h)/2;
        if (cal(m) < total) h = m - 1;
        else l = m + 1;
    }
    cout<<h;
}
