
#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
//#include <regex>

/* g++ -g -std=c++0x */
/* g++ -g -std=c++11 */

using namespace std;

// std::ios::sync_with_stdio(false);

// freopen("input.txt", "rt", stdin);
// freopen("output.txt", "wt", stdout);

#define ALL(c)          (c).begin(), (c).end()
#define ALLR(c)         (c).rbegin(), (c).rend()
#define FOR(i,a,b)      for (int i=(a); i < (b); ++i)
#define FORR(i,a,b)     for (int i=(a); i > (b); --i)
#define FOR_ALL(i,c)    for (__typeof((c).begin()) i=(c).begin();   \
                             i != (c).end(); ++i)
#define FOR_ALLR(i,c)   for (__typeof((c).rbegin()) i=(c).rbegin(); \
                             i != (c).rend(); ++i)
#define SZ(array)       (sizeof(array)/sizeof(array[0]))
#define lc(x)           (x<<1)     /* 2*x */
#define rc(x)           (x<<1 | 1) /* 2*x+1 */
#define lowbit(x)       (x & (-x)) /* 0b10100 -> 0b100 */

typedef long long       LL;
typedef map<int,int>    MII;
typedef pair<int,int>   PII;
typedef set<int>        SI;
typedef vector<bool>    VB;
typedef vector<double>  VD;
typedef vector<int>     VI;
typedef vector<string>  VS;

/* check if a key is in container C */
template <class C>
inline bool in_(const typename C::key_type& k, const C& A)
{ return A.find(k) != A.end(); }
inline bool in_(const string& s, const string& S)
{ return S.find(s) != string::npos; }

/*
 * Editorial:
 *
 * All positive integers can be obtained by performing the following two
 * types of operations to 1 (zero or more times):
 *
 * Add 1. By this operation, the sum of digits increases by one (unless
 * the last digit is 9, but this is not important).
 *
 * Multiply the current number by 10. The sum of digits remains the
 * same.
 *
 * Construct a graph with infinite number of vertices. Each vertex
 * corresponds to a positive integer. In this graph,
 *
 * For each x, we add an edge from x to x+1  with cost 1.
 * For each x, we add an edge from x to 10*x with cost 0.
 *
 * The answer is (the shortest distance from 1 to one of multiples of K
 * in this graph) plus one.
 *
 * We can compress this graph to vertices. When x=y (mod K), assume that
 * x and y are the same vertex. Then, in this graph, the answer is the
 * shortest distance from 1 to 0, plus one.
 *
 * Note: Isn't the trouble with '9' important? Suppose that the
 * algorithm above finds an invalid solution that contains a digit "10"
 * at position i. However, due to the periodicity of powers of tens
 * (when K is comprime to 10) we can find another j such that 10^i and
 * 10^j are same in modulo K, so we can move one digit from i to j. Even
 * when K is not coprime to 10, we can make it periodic by attaching
 * sufficient number of zeroes at the end.
 */

const int inf = 1e9;
const int maxv = 1e5+5;
int dist[maxv];

int main()
{
/* #ifndef ONLINE_JUDGE */
/*     freopen("foo", "rt", stdin); */
/* #endif */
    LL K;
    while (cin >> K) {
        FOR(i,0,maxv)
            dist[i] = inf;
        dist[1] = 0;
        deque<int> Q; Q.push_back(1);
        while (Q.size()) {
            const int u = Q.front(); Q.pop_front();
            const int v = (u+1) % K;
            const int d = dist[u]+1;
            if (d < dist[v]) {
                dist[v] = d;
                Q.push_back(v);
            }
            const int w = u*10 % K;
            if (dist[u] < dist[w]) {
                dist[w] = dist[u];
                Q.push_front(w);
            }
        }
        cout << dist[0]+1 << endl;
    }
    return 0;
}
