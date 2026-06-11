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

VI adj[112345];
int color[112345] = {};

bool dfs(int v, int c){
    color[v] = c;
    for(int p : adj[v]){
        if(color[p] == color[v]) return false;

        if(color[p] == 0 && !dfs(p,-c)) return false;
    }

    return true;
}

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL N,M; cin >> N >> M;
    REP(i,M){
        int a,b; cin >> a >> b;
        a--; b--;
        adj[a].eb(b);
        adj[b].eb(a);
    }

    bool bip = dfs(0,1);

    if(bip){
        LL bcnt = 0, wcnt = 0;
        REP(i,N){
            if(color[i] == 1) bcnt++;
            else wcnt++;
        }
        cout << bcnt * wcnt - M << endl;
    }
    else{
        cout << N * (N-1) / 2 - M << endl;
    }

}