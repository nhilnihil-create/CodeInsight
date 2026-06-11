#include <iostream>
#include <iomanip>
#include <algorithm>
#include <assert.h>
#include <complex>
#include <utility>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <cmath>
#include <bitset>
#include <cctype>
#include <set>
#include <map>
#include <unordered_map>
#include <numeric>
#include <functional>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define rrep(i,a) for(ll i=ll(a-1);i>=0;--i)
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

const ll INF = 1e10;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ll EPS = 1e-10;
int sgn(const double a){
    return (a < -EPS ? -1 : (a > EPS ? +1 : 0));
}
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> tri;
typedef pair<double,double> point;
typedef complex<double> Point;
const ll MAX = 30000;
constexpr ll nx[8] = {1,0,-1,0,1,-1,1,-1};
constexpr ll ny[8] = {0,1,0,-1,1,1,-1,-1};
vector<bool> is_prime(101,1);
void init(){
    is_prime[0] = is_prime[1] = 0;
    rep(i,2,101){
        if (is_prime[i]){
            for (ll j = 2*i;j < 101;j += i){
                is_prime[j] = 0;
            }
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    init();
    ll n;
    cin >> n;
    vector<ll> factor(101,0);
    rep(i,1,n+1){
        ll b = i;
        rep(j,i+1){
            if (is_prime[j]){
                while (b%j == 0){
                    factor[j]++;
                    b /= j;
                }
            }
        }
    }
    // 3 5 15 25 75
    vector<ll> cnt(5);
    rep(i,n+1){
        if (factor[i] >= 2) cnt[0]++;
        if (factor[i] >= 4) cnt[1]++;
        if (factor[i] >= 14) cnt[2]++;
        if (factor[i] >= 24) cnt[3]++;
        if (factor[i] >= 74) cnt[4]++;
    }
    ll ans = cnt[4]+cnt[3]*max(cnt[0]-1,0ll)+cnt[2]*max(cnt[1]-1,0ll)+cnt[1]*(cnt[1]-1)/2*max(cnt[0]-2,0ll);
    PRINT(ans);
}

