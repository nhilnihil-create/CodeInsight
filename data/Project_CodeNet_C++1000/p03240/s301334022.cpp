#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define rrep(i,x,y) for(ll i=(ll)(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
#define itrout(x) for(int i=0;i<x.size();i++) {cout << x[i] << (i==x.size()-1 ? "\n" : " ");}
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define itrdebug(x) cerr << #x << " "; for (auto & el : (x)) {cerr << (el) << " ";} cerr << endl
#define dassert(...) assert(__VA_ARGS__)
#else
#define debug(x)
#define itrdebug(x)
#define dassert(...)
#endif
//#define int long long

typedef long long ll;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-8;

void solve(long long N, std::vector<long long> x, std::vector<long long> y, std::vector<long long> h){
    rep(cx, 0,101) rep(cy,0,101) {
        bool valid = true;
        ll H = -1;
        rep(i,0,N) {
            if (h[i] != 0) {
                H = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
                break;
            }
        }
        if (H == -1) continue;
        rep(i,0,N) {
            if (max<ll>(H - abs(x[i] - cx) - abs(y[i] - cy), 0) != h[i]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            vector<ll> answer = {cx, cy, H};
            itrout(answer)
            return;
        }
    }
}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long long N;
    scanf("%lld",&N);
    std::vector<long long> x(N);
    std::vector<long long> y(N);
    std::vector<long long> h(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
        scanf("%lld",&h[i]);
    }
    solve(N, std::move(x), std::move(y), std::move(h));
    return 0;
}
