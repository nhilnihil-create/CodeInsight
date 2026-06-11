#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;

const int mod = 1000000007;
const int inf = 1e9;
#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a), t(b);
    for(int i = 0; i < a; i++) cin >> s[i];
    for(int i = 0; i < b; i++) cin >> t[i];
    auto solve1 = [&](ll x) {
        vector<ll> a(2, -1);
        ll ret = 1e18;
        auto it = lower_bound(s.begin(), s.end(), x);
        if(it!=s.end())a[0] = *it;
        if(it!=s.begin()) it--;
        a[1] = *it;
        for(int i = 0; i < 2; i++) if(a[i] != -1){
            auto it2 = lower_bound(t.begin(), t.end(), a[i]);
            if(it2!=t.end()) {
                chmin(ret, abs(x-a[i])+abs(a[i]-*it2));
            }
            if(it2!=t.begin()) {
                it2--;
                chmin(ret, abs(x-a[i])+abs(a[i]-*it2));
            }
        }
        return ret;
    };

    auto solve2 = [&](ll x) {
        vector<ll> a(2, -1);
        ll ret = 1e18;
        auto it = lower_bound(t.begin(), t.end(), x);
        if(it!=t.end())a[0] = *it;
        if(it!=t.begin()) it--;
        a[1] = *it;
        for(int i = 0; i < 2; i++) if(a[i] != -1){
            auto it2 = lower_bound(s.begin(), s.end(), a[i]);
            if(it2!=s.end()) {
                chmin(ret, abs(x-a[i])+abs(a[i]-*it2));
            }
            if(it2!=s.begin()) {
                it2--;
                chmin(ret, abs(x-a[i])+abs(a[i]-*it2));
            }
        }
        return ret;
    };

    while(q--) {
        ll x;
        cin >> x;
        ll ans = min(solve1(x), solve2(x));
        cout << ans << endl;
    }
}