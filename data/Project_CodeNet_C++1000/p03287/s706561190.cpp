#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>
#include <bitset>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
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
const ll INF = 1e10;
const ll MOD = 1000000007;
typedef pair<ll,ll> P;
const ll MAX = 200005;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    ll a[n+2],b;
    a[0] = 0;
    a[n+1] = INF;
    rep(i,n){
        cin >> b;
        a[i+1] = (a[i]+b)%m;
    }
    sort(a,a+n+1);
    ll ans = 0,cnt = 1;
    rep(i,n+1){
        if (a[i] == a[i+1]) cnt++;
        else{
            ans += cnt*(cnt-1)/2;
            cnt = 1;
        }
    }
    PRINT(ans);
}
