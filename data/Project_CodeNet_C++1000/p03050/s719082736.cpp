#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

vector<ll> divisor(ll n){
    vector<ll> res;
    for (ll i=1;i*i<=n;++i) if (n%i==0){
        res.emplace_back(i);
        if (i!=n/i) res.emplace_back(n/i);
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> cand=divisor(N);
    ll ans=0;
    for (ll x:cand){
        ll y=N/x-1;
        if (x<y) ans+=y;
    }
    cout << ans << '\n';
}