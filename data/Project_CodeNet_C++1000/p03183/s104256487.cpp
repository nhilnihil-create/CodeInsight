
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
/* #include <regex> */

using namespace std;

/* g++ -g -std=c++11 */

/* freopen("input.txt", "rt", stdin); */
/* freopen("output.txt", "wt", stdout); */

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

const LL inf = 1e16;
const int maxn = 1e3+3;
int n,w[maxn],c[maxn],v[maxn], sorted[maxn];

bool cmp(const int i, const int j)
{ return w[i]+c[i] < w[j]+c[j]; }

int main()
{
#ifdef foo_
    freopen("foo", "rt", stdin);
#endif
    ios::sync_with_stdio(false);
    while (cin >> n) {
        int maxw = 0;
        FOR(i,0,n) {
            cin >> w[i] >> c[i] >> v[i];
            maxw = max(maxw,max(w[i],c[i])); sorted[i] = i;
        }
        maxw *= 2;
        sort(sorted,sorted+n,cmp);
        vector<LL> dp(maxw+1,-inf);
        dp[0] = 0;
        FOR(i,0,n) {
            const int j = sorted[i];
            FORR(k,maxw-w[j],-1) if (c[j] >= k) 
                dp[k+w[j]] = max(dp[k+w[j]], dp[k]+v[j]);
        }
        LL ans = 0;
        FOR(i,0,maxw+1)
            ans = max(ans,dp[i]);
        cout << ans << endl;
    }
    return 0;
}
