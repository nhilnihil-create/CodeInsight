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
const ll INF = 1e16;
const ll MOD = 1000000007;
typedef pair<ll,ll> P;
const ll MAX = 200005;
vector<bool> IsPrime;
void sieve(size_t max){
    if(max+1 > IsPrime.size()){     
        IsPrime.resize(max+1,true); 
    } 
    IsPrime[0] = false;
    IsPrime[1] = false;

    for(size_t i=2; i*i<=max; ++i) 
        if(IsPrime[i])
            for(size_t j=2; i*j<=max; ++j) 
                IsPrime[i*j] = false;      
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sieve(55555);
    int n;
    cin >> n;
    vector<int> ans;
    rep(i,1,55555){
        if (IsPrime[i] && i%5 == 1)  ans.push_back(i);
    }
    rep(i,n-1) cout << ans[i] << " ";
    PRINT(ans[n-1]);
}
