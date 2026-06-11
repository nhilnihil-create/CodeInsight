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
const ll INF = 1e9;
const ll MOD = 1000000007;
typedef pair<ll,ll> P;
const ll MAX = 20000;
constexpr ll nx[4] = {1,0,-1,0};
constexpr ll ny[4] = {0,1,0,-1};
ll n;
vector<vector<ll>> to(10005);
vector<ll> d(10005,-1);
void dfs(ll v){
    for(ll u:to[v]){
        if (d[u] != -1) continue;
        d[u] = d[v]+1;
        dfs(u);
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    ll a,b;
    rep(i,n-1){
        cin >> a >> b;
        --a;
        --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<ll> c(n),ans(n);
    cins(all(c));
    RSORT(c);
    ll cnt = 0;
    rep(i,1,n) cnt += c[i];
    d[0] = 0;
    dfs(0);
    vector<P> p;
    rep(i,n){
        p.push_back(P(d[i],i));
    }
    SORT(p);
    rep(i,n){
        tie(a,b) = p[i];
        ans[b] = c[i];
    }
    PRINT(cnt);
    array_output(all(ans));
}
