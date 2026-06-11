#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <x86intrin.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <assert.h>
#include <numeric>
#include <new>
#define BIT(nr) (1ULL << (nr))
#define int long long
//#define ll long long
#define double long double
#define mod 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	//ない環境用
#define LL_HALFMAX 9223372036854775807 / 2	//ない環境用
#define MIN -(9223372036854775807 / 2)
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define mp make_pair
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }


using namespace std;

signed main() {

    int L;
    cin >> L;
    vector<pair<pair<int, int>, int> > p;
    int mx = 64 - __builtin_clzll(L) - 1;

    //最大以外の各桁について0, 1の辺を張る
    rep(i, 19) {
        p.push_back({ { i, i + 1 }, 0 });
    }
    rep(i, mx) {
        p.push_back({ {i, i + 1}, 1 << (mx - i - 1) });
    }
    RREP(i, mx) {
        int v = mx - i - 1;
        if (L & 1 << i) {
            p.push_back({ { 0, v + 1 } , ((L >> (i + 1))) << (i + 1) });
        }
    }
    cout << 20 << ' ' << p.size() << endl;
    //最大桁は最初のノードから生える辺で立てる、最大桁が立っている場合はそれ以外のけたでL未満であることが確定する必要がある
    for (auto pa : p) {
        cout << pa.first.first + 1 << " " << pa.first.second + 1 << " " << pa.second << "\n";
    }


    return 0;
}
