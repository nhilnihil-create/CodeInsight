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
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll h,w,n,s1,s2;
    string s,t;
    cin >> h >> w >> n >> s1 >> s2 >> s >> t;
    --s1;
    --s2;
    reverse(all(s));
    reverse(all(t));
    ll l = 0,r = w;
    rep(i,n){
        if (t[i] == 'L') r = min(w,r+1);
        if (t[i] == 'R') l = max(0ll,l-1);
        if (s[i] == 'L') l++;
        if (s[i] == 'R') r--;
        if (l >= r){
            PRINT("NO");
            return 0;
        }
    }
    if (s2 < l || r <= s2){
        PRINT("NO");
        return 0;
    }
    l = 0;
    r = h;
    rep(i,n){
        if (t[i] == 'U') r = min(h,r+1);
        if (t[i] == 'D') l = max(0ll,l-1);
        if (s[i] == 'U') l++;
        if (s[i] == 'D') r--;
        if (l >= r){
            PRINT("NO");
            return 0;
        }
    }
    if (s1 < l || r <= s1){
        PRINT("NO");
        return 0;
    }
    PRINT("YES");
}



