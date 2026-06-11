#include <bits/stdc++.h>
using namespace std;

using i64=int64_t;

#define rep(i,x,y) for(i64 i=i64(x),i##_max_for_repmacro=i64(y); i<i##_max_for_repmacro; ++i)
#define debug(x) #x << "=" << (x)
 
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif
 
const int inf=1.01e9;
const i64 inf64=4.01e18;
const double eps=1e-9;
 
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
        os << v << ",";
    }
    os << "]";
    return os;
}

i64 extgcd(i64 a, i64 b, i64 &x, i64 &y) {
    i64 d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

i64 mod_inverse(i64 a, i64 m) {
    i64 x, y;
    if (extgcd(a, m, x, y) == 1) return (x + m) % m;
    return 0;
}

void solve(){
    i64 N;
    cin >> N;

    vector<i64> A(N+1);
    rep(i,1,N+1) cin >> A[i];

    i64 mod=1000'000'007;

    vector<i64> fact(200000);
    fact[0]=1;
    rep(i,1,200000) fact[i]=fact[i-1]*i%mod;

    vector<i64> h(200000),s(200000);
    rep(i,1,200000){
        h[i]=(1+mod_inverse(i,mod)*s[i-1]%mod)%mod;
        s[i]=(s[i-1]+h[i])%mod;
    }

    i64 ans=0;
    rep(i,1,N+1){
        i64 c=fact[N]*(h[i]+h[N-i+1]-1+mod)%mod;
        ans+=c*A[i];
        ans%=mod;
    }

    cout << ans << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    //rep(i,0,10) cout << f(i) << endl;
    return 0;
}
