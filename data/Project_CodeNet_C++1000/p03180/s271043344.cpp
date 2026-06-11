#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(auto i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end(); ++it)
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const ll INF = ~(1<<31);
#define fs first
#define sc second
#define pb push_back

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
    return (a % b + b) % b;
}

ll n;
ll A[20][20];

ll calc(ll H) {
    ll tts = 0;
    rep(i,0,n) {
        rep(j,0,n) {
            if(H & (1<<i) && H & (1<<j)) {
                tts += A[i][j];
            }
        }
    }
    return tts;
}

void wr(ll a) {
    rep(i,0,n) {
        if(a & (1<<i)) cout << 1;
        else cout << 0;
    }
    cout << endl;
}

ll memo[1<<17];
ll dp(ll have) {
    if(memo[have] != -1) return memo[have];
    ll val = calc(have);
    ll mask = have;
    for(ll submask = mask; ; submask = (submask - 1) & mask) {
        if(submask == 0) break;
        if(submask != mask) {
            val = max(val, dp(submask) + dp(have ^ submask));
        }
    }
    return memo[have] = val;
}

int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    rep(i,0,n) {
        rep(j,0,n) cin >> A[i][j];
    }
    memset(memo,-1,sizeof(memo));
    cout << dp((1<<n)-1)/2 << endl;
    return 0;
}
