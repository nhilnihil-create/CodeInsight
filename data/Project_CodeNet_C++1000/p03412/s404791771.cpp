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
    VL a(N), b(N);
    REP(i,N) cin >> a[i];
    REP(i,N) cin >> b[i];
    LL ans = 0;

    for(int i = 0; i <= 30; i++) //i bit
    //for(int i = 0; i <= 4; i++) //i bit
    {
        LL Tn = 1LL << (i+1);
        VL xs,ys;
        REP(j,N){
            xs.pb(a[j] % Tn);
            ys.pb(b[j] % Tn);
        }
        sort(xs.begin(),xs.end());
        sort(ys.begin(),ys.end());
        LL cnt = 0;
        //cout << printVector(xs) << endl;
        //cout << printVector(ys) << endl;

        for(LL x : xs)  {
            int idx = lower_bound(ys.begin(),ys.end(), 4 * (1LL << (i))-x) - lower_bound(ys.begin(),ys.end(), 3 * (1LL << (i))-x) + 1;

            int idx1 = lower_bound(ys.begin(),ys.end(), 2 * (1LL << (i))-x) - lower_bound(ys.begin(),ys.end(), (1LL << (i))-x) + 1;

            cnt += idx + idx1;
        }
        if((cnt)%2 == 1) {
            ans += (1LL << i);
        }

    }
    cout << ans << endl;

}