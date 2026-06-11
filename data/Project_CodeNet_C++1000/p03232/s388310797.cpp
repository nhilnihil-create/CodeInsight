#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

ll f[100010];

void calc() {
    f[0] = 1;
    rep(i, 1, 100010) {
        f[i] = f[i - 1] * i;
        f[i] %= mod;
    }
}

ll pow_mod(ll a, ll b, ll m){
    ll ret = 1;
    while (b > 0) {
        if (b & 1) {
            ret = ret * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ret;
}

ll inv_mod(ll a, ll m){
    return pow_mod(a, m - 2, m);
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N){
        cin >> A[i];
    }
    calc();

    
    ll ans = 0;
    
    vector<ll> S(N);
    S[0] = 1;
    rep(i, 1, N) {
        S[i] = S[i - 1] + inv_mod(i + 1, mod);
        S[i] %= mod;
    }
    
    rep(i, N) {
        ll tmp = A[i] * ((S[i] + S[N - i - 1] - 1) % mod);
        ans += tmp;
        ans %= mod;
    }
    ans *= f[N];
    ans %= mod;
    ans += mod;
    ans %= mod;
    output(ans);
    

    
    

    
    
    return 0;
}
