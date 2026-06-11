#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

#define rep(i, x, y) for (i64 i = i64(x), i##_max_for_repmacro = i64(y); i < i##_max_for_repmacro; ++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

const int inf = 1.01e9;
const i64 inf64 = 4.01e18;
const double eps = 1e-9;

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "[";
    for (const auto &v : vec) {
        os << v << ",";
    }
    os << "]";
    return os;
}

template <typename T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

void solve() {
    //const i64 mod = 1'000'000'007;

    i64 N;
    cin >> N;

    using triple = tuple<i64,i64,i64>;
    vector<triple> wsv(N);
    rep(i,0,N) {
        i64 wi,si,vi;
        cin >> wi >> si >> vi;
        wsv[i]=make_tuple(wi,wi+si,vi);
    }

    sort(begin(wsv),end(wsv),[](const triple& a, const triple& b){
       return get<1>(a)<get<1>(b);
    });

    vector<i64> w(N),s(N),v(N);
    rep(i,0,N){
        tie(w[i],s[i],v[i])=wsv[i];
    }

    const i64 maxws=20010;
    static i64 dp[maxws]; // (全体の重さ)
    fill_n((i64*)dp,maxws,-inf64);
    dp[0]=0;
    dp[w[0]]=v[0];

    rep(i,1,N){
        for(i64 j=s[i]; j>=w[i]; --j){;
            chmax(dp[j],dp[j-w[i]]+v[i]);
        }
    }

    i64 ans=-inf64;
    rep(i,0,maxws) chmax(ans,dp[i]);

    cout << ans << endl;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
