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

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    VL C(N); REP(i,N) cin >> C[i];
    VL dp(N,0);
    int last[212345] = {};
    REP(i,212345) last[i] = -1;
    dp[0] = 1;
    last[C[0]] = 0;
    FOR(i,1,N){
        dump(i)
        dump(C[i])
        dump(last[C[i]])
        dump(dp[last[C[i]]])

        if(last[C[i]] == -1 || last[C[i]] == i-1){
            dp[i] = dp[i-1];
            last[C[i]] = i;
        }
        else{
            dp[i] = dp[i-1] + dp[last[C[i]]];
            last[C[i]] = i;
        }
        dp[i] %= MOD;
    }
    REP(i,N){
        dump(i)
        dump(dp[i])
    }
    cout << dp[N-1] << endl;

}
