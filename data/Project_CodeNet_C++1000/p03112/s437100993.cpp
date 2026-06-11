#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e18;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a+2), t(b+2);
    rep(i,a) cin >> s[i+1];
    rep(i,b) cin >> t[i+1];
    s[0] = t[0] = -INF;
    s[a+1] = t[b+1] = INF;
    rep(i,q){
        ll x;
        cin >> x;
        auto Sleft = lower_bound(s.begin(), s.end(), x);
        auto Sright = lower_bound(s.begin(), s.end(), x);
        auto Tleft = lower_bound(t.begin(), t.end(), x);
        auto Tright = lower_bound(t.begin(), t.end(), x);
        Sleft--;
        Tleft--;
        ll ans = abs(x - min(*Sleft, *Tleft));
        chmin(ans, abs(max(*Sright, *Tright) - x));
        chmin(ans, abs((x - *Sleft)*2 + *Tright - x));
        chmin(ans, abs((x - *Tleft)*2 + *Sright - x));
        chmin(ans, abs((*Sright - x)*2 + x - *Tleft));
        chmin(ans, abs((*Tright - x)*2 + x - *Sleft ));
        cout << ans << endl;
    }
    return 0;
}