#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>
#include <cstdio>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>
#include <map>
#include <cstring>
#include <set>
#include <functional>
#include <iomanip>

using namespace std;

//#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ;
#endif

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back

//#define int long long

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

template <typename T>
std::string printVector(const std::vector<T> &data)
{
    std::stringstream ss;
    std::ostream_iterator<T> out_it(ss, ", ");
    ss << "[";
    std::copy(data.begin(), data.end() - 1, out_it);
    ss << data.back() << "]";
    return ss.str();
}

const int MOD = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    VL A(N); REP(i,N) cin >> A[i];

    VL accinv(N+1);
    accinv[1] = 1;
    FOR(i,2,N+1){
        accinv[i] = (accinv[i-1] + modinv(i,MOD)) % MOD;
    }

    VL ans(N+1);

    FOR(i,1,N+1){
        if(i == 1){
            ans[i] = accinv[N];
        }
        else if(i == N){
            ans[i] = accinv[N];
        }
        else{
            int st = abs(1-i) + 1;
            int fi = abs(N-i) + 1;
            ans[i] = (accinv[st] + accinv[fi] - 1) % MOD;
        }

        ans[i] = (ans[i]*A[i-1])%MOD;
    }
    LL tmp = 0;

    FOR(i,1,N+1){
        dump(i)
        dump(ans[i])
        tmp += ans[i];
        tmp %= MOD;
    }
    FOR(i,1,N+1){
        tmp *= i;
        tmp %= MOD;
    }
    cout << tmp << endl;

}
