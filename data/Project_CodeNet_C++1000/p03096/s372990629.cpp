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
const ll MAX = 100010;
constexpr ll nx[8] = {1,0,-1,0,-1,-1,1,1};
constexpr ll ny[8] = {0,1,0,-1,-1,1,-1,1};
vector<ll> dp(200010,-1),c(200010,-1),nc;
vector<vector<ll>> nex(200010);
ll n;
ll get(ll k){
    if (dp[k] != -1) return dp[k];
    if (k >= n) return dp[k] = 1;
    int l = *upper_bound(all(nex[nc[k]]),k);
    if (l == 1000000) return dp[k] = get(k+1)%MOD;
    else return dp[k] = (get(k+1)+get(l))%MOD;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    rep(i,n) cin >> c[i];
    rep(i,n) c[i]--;
    rep(i,n){
        if (c[i] != c[i+1]) nc.push_back(c[i]);
    }
    n = nc.size();
    rep(i,n){
        nex[nc[i]].push_back(i);
    }
    rep(i,200010){
        nex[i].push_back(1000000);
    }
    PRINT(get(0));
}
