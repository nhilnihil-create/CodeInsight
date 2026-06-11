#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>
#include <bitset>
#include <cctype>
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
template<typename T>
vector<T> table(int n, T v) { return vector<T>(n, v); }

template <class... Args>
auto table(int n, Args... args) {
    auto val = table(args...);
    return vector<decltype(val)>(n, move(val));
}
const ll INF = 1e16;
const ll MOD = 1000000007;
typedef pair<ll,ll> P;
const ll MAX = 200005;
int nx[4] = {1,0,-1,0};
int ny[4] = {0,1,0,-1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,b;
    cin >> n;
    ll a[n][20] = {0};
    rep(i,n){
        cin >> b;
        rep(j,20){
            if (b&(1<<j)) a[i][j] = 1;
        }
    }
    ll m[20] = {0},r = 0,ans = 0;
    rep(l,n){
        bool ok = 1;
        ll cnt = 0;
        ll len = r-l;
        while(ok){
            rep(k,20){
                if(m[k]+a[r][k] > 1) ok = 0;
            }
            if (ok){
                rep(k,20) m[k] += a[r][k];
                r++;
                cnt++;
            }
        }
        ans += (cnt+len)*(cnt+len+1)/2-len*(len+1)/2;
        rep(k,20){
            m[k] -= a[l][k];
        }
    }
    PRINT(ans);
}
