#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T> >;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define repb(i, n) for(ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for(ll i = (a); i < (b); i++)
#define reprb(i, a, b) for(ll i = (b)-1; i >= (a); i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
const ld EPS = 1e-12L;
const ld PI = 3.1415926535897932385L;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powint(ull x, ll y){ ll r=1; while(y){ if(y&1) r*=x; x*=x; y>>=1; } return r; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class S, class T>inline bool chmax(S &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class S, class T>inline bool chmin(S &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n, k;
    cin >> n >> k;
    vp sushi(n);
    rep(i, n){
        cin >> sushi[i].second >> sushi[i].first;
    }
    vll ans(100001, 0);
    vi cnt(100001, 0);
    sort(ALL(sushi));
    reverse(ALL(sushi));
    dump(sushi);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    priority_queue<pll, vector<pll>, greater<pll>> pq2;
    ll tmp = 0;
    rep(i, k){
        if(cnt[sushi[i].second] == 0){
            pq2.emplace(sushi[i]);
        }else{
            pq.emplace(sushi[i]);
        }
        cnt[sushi[i].second]++;
        tmp += sushi[i].first;
    }
    rep(i, 20){
        dump(i, cnt[i]);
    }
    ans[pq2.size()] = tmp;
    ll j = k;
    while(j < n && SZ(pq2) < k){
        dump(pq.top().first, pq2.top().first);
        tmp -= pq.top().first;
        pq.pop();
            dump(j, cnt[sushi[j].second]);
        while(j < n && cnt[sushi[j].second]){
            j++;
        }
        if(j == n) break;
        pq2.emplace(sushi[j]);
        tmp += sushi[j].first;
        cnt[sushi[j].second]++;
        ans[pq2.size()] = tmp;
    }
    ll ansm = 0;
    rep(i, 100001){
        if(ans[i] > 0){
            chmax(ansm, ans[i]+i*i);
            dump(i, ans[i]);
        }
    }
    cout << ansm << endl;
    return 0;
}
