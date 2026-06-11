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
inline bool Yes(bool condition){ if(condition) PRINT("Yes"); else PRINT("No"); }
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
const ll INF = 1e17;
const ll MOD = 1000000007;
typedef pair<ll,ll> P;
const ll MAX = 200005;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,C;
    cin >> n >> C;
    vector<vector<ll>> a(35,vector<ll>(100005,0));
    ll s,t,c;
    rep(i,n){
        cin >> s >> t >> c;
        a[c-1][s]++;
        a[c-1][t]--;
    }
    vector<ll> b(100005,0);
    rep(i,C){
        rep(j,100002){
            if (a[i][j+1] > 0) b[j] += a[i][j+1];
            if (a[i][j] < 0) b[j] += a[i][j];
        }
    }
    rep(i,100002) b[i+1] += b[i];
    PRINT(*max_element(all(b)));
}
