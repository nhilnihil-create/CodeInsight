#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

const ll MAX_N = 1LL << 19;
mat bit(20,vec(MAX_N,0));//1-indexed
ll k = 0;
ll sum(ll i){
    ll s = 0;
    while(i > 0){
        s += bit[k][i];
        i -= i & -i;
    }
    return s;
}
void add(ll i, ll x){
    while(i < MAX_N){
        bit[k][i] += x;
        i += i & -i;
    }
}

bool simu(ll x, vec a) {
    vec s(N+1,0);
    reps(i,1,N+1){
        s[i] = s[i-1] + (a[i-1] >= x) - (a[i-1] < x);
    }
    //bit[i]への代入をbit[i+100010]に(個数保存用)
    ll ans = 0;
    reps(i,1,N+1){
        ans += (s[i] - s[0]) >= 0;
        ans += sum(s[i] + 100010);
        add(s[i] + 100010, 1);
        //cout<<x<<' '<<i<<' '<<ans<<endl;
    }
    return (ans >= ((N+1)*N/2 + 1LL)/2);
}

int main() {
    cin>>N;
    vec a(N);
    rep(i,N) cin>>a[i];
    vec sorted(N);
    rep(i,N) sorted[i] = a[i];
    sort(sorted.begin(),sorted.end());
    ll lb = 0, ub = N;
    while(ub - lb > 1){
        ll cen = (ub + lb)/2;
        (simu(sorted[cen], a) ? lb : ub) = cen;
        ++k;
    }
    cout<<sorted[lb]<<endl;
}
