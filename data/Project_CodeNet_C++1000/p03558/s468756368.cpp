// {{{
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

typedef long int i32;
typedef unsigned long int u32;
typedef long long int i64;
typedef unsigned long long int  u64;
typedef pair<i32, i32> PII;
typedef vector<i32> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<i32, i32> MPII;
typedef set<i32> SETI;
typedef multiset<i32> MSETI;
#define IN(x) cin >> x;
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define ZERO(a) memset(a, 0, sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define BTW(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;

template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
// }}}

const int MAX_K = (i32)1e5;
bool used[MAX_K];

struct xyz {
    u64 x;
    u64 y;
    u64 z;
};
int main() {
    u64 K;
    IN(K);
    auto q = deque<struct xyz>();
    q.PB({1, 1, 1});
    while(1) {
        auto xyz = q.front();
        u64 x = xyz.x;
        u64 y = xyz.y;
        u64 z = xyz.z;
        q.pop_front();
        if(used[x]) {
            continue;
        }
        if(x == 0) {
            cout << y << endl;
            break;
        }
        used[x] = true;
        if(z == 9) {
            q.push_front({(x+1)%K, y, 0});
        } else {
            q.push_back({(x+1)%K, y+1, z+1});
        }
        q.push_front({x*10%K, y, 0});
    }
        
    return 0;
}

