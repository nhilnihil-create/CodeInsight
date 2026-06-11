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

#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ;
#endif

#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS)
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
int ans = 0;
int cnt[13] = {};
int a[30];

int solve(int mask){
    int n = 0;
    a[n++] = 0;
    for(int i = 0; i < 12; i++){
        if(cnt[i+1] == 0) continue;
        if(cnt[i+1] == 2){
            a[n++] = i+1;
            a[n++] = -(i+1);
            continue;
        }
        if((mask >> i) & 1)
            a[n++] = i+1;
        else
            a[n++] = -(i+1);
    }
    sort(a,a+n);
    a[n++] = a[0] + 24;
    int res = 24;
    for(int i = 0; i < n-1; i++)
        res = min(res, a[i+1]-a[i]);

    return res;

}

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    VI D(N);
    cnt[0]++;
    REP(i,N) {
        cin >> D[i];
        cnt[D[i]]++;
    }
    FOR(i,1,13){
        if(cnt[i] > 2){
            cout << 0 << endl;
            return 0;
        }
    }
    if(cnt[0] >= 2){
        cout << 0 << endl;
        return 0;
    }

    for(int mask = 0; mask < (1 << 12); mask++){
        ans = max(ans,solve(mask));
    }
    cout << ans << endl;


}
