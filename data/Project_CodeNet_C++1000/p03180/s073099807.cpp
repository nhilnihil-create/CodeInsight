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

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

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

template <typename T>
void print_array(const T &ary, int size){
    REP(i,size){
        cout << ary[i] << " ";
    }
    cout << endl;
}

const int MOD = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;
const double EPS = (1e-10);

const int MAX_S = (1 << 16) + 10;

int nbit(LL S, int i){
    if((S >> i) & 1) return 1;
    else return 0;
}

LL dp[MAX_S];
int N;

vector<vector<LL>> a;

LL rec(LL S){
    if(dp[S] != -LINF) return dp[S];

    LL temp = 0;
    REP(i,N) FOR(j,i+1,N) if(nbit(S,i) && nbit(S,j)) temp += a[i][j];
    for(LL T = (S-1) & S; T > 0; T = (T-1)&S){
        chmax(temp,rec(T)+rec(S^T));
    }
    return dp[S] = temp;
}

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(12);

    cin >> N;
    a = vector<vector<LL>>(N,VL(N));
    REP(i,N){
        REP(j,N) cin >> a[i][j];
    }
    REP(i,MAX_S) dp[i] = -LINF;

    cout << rec((1 << N)-1) << endl;

}
