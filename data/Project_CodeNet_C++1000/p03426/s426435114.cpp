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
#include <set>
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
const ll INF = (1ll<<31)-1;
const ll MOD = 1000000007;
typedef pair<ll,ll> P;
const ll MAX = 200005;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w,d,a;
    cin >> h >> w >> d;
    vector<P> grid(h*w);
    rep(i,h){
        rep(j,w){
            cin >> a;
            grid[a-1] = P(i,j);
        }
    }
    vector<ll> cost(h*w);
    rep(i,d){
        cost[i] = 0;
        int index = i;
        while(index+d < h*w){
            index += d;
            cost[index] = cost[index-d]+abs(grid[index].first-grid[index-d].first)+abs(grid[index].second-grid[index-d].second);
        }
    }
    int q,l,r;
    cin >> q;
    rep(i,q){
        cin >> l >> r;
        PRINT(cost[r-1]-cost[l-1]);
    }
}
