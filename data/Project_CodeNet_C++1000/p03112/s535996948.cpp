#include <iostream>
#include <algorithm>
#include <complex>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>
#include <bitset>
#include <cctype>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
inline void Yes(bool condition){ if(condition) PRINT("Yes"); else PRINT("No"); }
template<class itr> void cins(itr first,itr last){
    for (auto i = first;i != last;i++){
        cin >> (*i);
    }
}
template<class itr> void array_output(itr start,itr goal){
    string ans = "",k = " ";
    for (auto i = start;i != goal;i++) ans += to_string(*i)+k;
    if (!ans.empty()) ans.pop_back();
    PRINT(ans);
}
ll gcd(ll a, ll b) {
    return a ? gcd(b%a,a) : b;
}
const ll INF = 1e18;
const ll MOD = 1000000007;
typedef pair<ll,ll> P;
const ll MAX = 100005;
constexpr ll nx[8] = {1,0,-1,0,-1,-1,1,1};
constexpr ll ny[8] = {0,1,0,-1,-1,1,-1,1};
vector<vector<ll>> g(200005);
vector<ll> cnt(200005,0);
vector<bool> done(200005,0);
void dfs(ll v){
    done[v] = 1;
    for (ll u:g[v]){
        if (done[u]) continue;
        cnt[u] += cnt[v];
        dfs(u);
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a,b,q,c,d;
    cin >> a >> b >> q;
    vector<ll> s,t;
    s.push_back(-INF);
    t.push_back(-INF);
    rep(i,a){
        cin >> c;
        s.push_back(c);
    }
    rep(i,b){
        cin >> c;
        t.push_back(c);
    }
    s.push_back(INF);
    t.push_back(INF);
    ll x;
    rep(i,q){
        cin >> x;
        ll si = lower_bound(all(s),x)-s.begin();
        ll ti = lower_bound(all(t),x)-t.begin();
        PRINT(min({max(s[si]-x,t[ti]-x),max(x-s[si-1],x-t[ti-1]),2*min(s[si]-x,x-t[ti-1])+max(s[si]-x,x-t[ti-1]),2*min(x-s[si-1],t[ti]-x)+max(x-s[si-1],t[ti]-x)}));
    }
}


