#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll n;

ll dfs(ll num){
    ll ret = 0;
    if(1 <= num && num <= n){
        bool s = false, f = false, t = false;
        ll m = num;
        while(m > 0){
            if(m%10 == 7) s = true;
            if(m%10 == 5) f = true;
            if(m%10 == 3) t = true;
            m /= 10;
        }
        if(s && f && t) ++ret;
    }
    if(num > n) return 0;
    ret += dfs(num*10 + 7);
    ret += dfs(num*10 + 5);
    ret += dfs(num*10 + 3);
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    ll ans = dfs(0);
    cout << ans << endl;
    return 0;
}
