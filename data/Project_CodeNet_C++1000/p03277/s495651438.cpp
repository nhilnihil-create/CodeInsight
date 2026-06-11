
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

/*
 * 二分一下最后的中位数, 然后将原序列中大于当前二分出来的值标为1,
 * 小于的标为-1. 那么只要一段区间的和 >=0, 那么这段区间的中位数
 * 就一定 >= 等于当前二分出来的值.
 *
 * So the task is to find how many sum(lft,rht)=sum[rht]-sum[lft] >= 0.
 * Basically finding how many sum[rht] >= sum[lft]. This is to find
 * the number of ordered pairs in n*(n+1)/2 pairs. Very similar to
 * count number of inverted pairs of an array.
 */

const int maxn = 1e5+5;
int A[maxn], B[maxn];
LL bit[maxn*2];

void add(const int i, const int v)
{
    for (int x = i; x < SZ(bit); x |= (x+1))
        bit[x] += v;
}

LL get(const int i)
{
    LL ans = 0;
    for (int x = i; x >= 0; x = (x&(x+1))-1)
        ans += bit[x];
    return ans;
}

int main()
{
    int n;
    while (cin >> n) {
        FOR(i,0,n) {
            cin >> A[i]; B[i] = A[i];
        }
        sort(B,B+n);
        const int m = unique(B,B+n) - &B[0];
        const LL total = 1LL*n*(n+1)/2;
        int lo = 0, hi = m-1;
        while (lo < hi) {
            const int mid = lo + (hi-lo+1)/2;
            memset(bit,0,sizeof(bit));
            /*
             * Move 0 to n, because of the '-' values. Since [i,i]
             * counts as >= 0 for any non-negative i, add(sum,1).
             */
            int sum = n; add(sum,1); /* accumulative sum */
            LL ordered = 0;
            FOR(i,0,n) {
                if (A[i] >= B[mid])
                    sum++;
                else
                    sum--;
                ordered += get(sum); add(sum,1);
            }
            if (ordered*2 >= total)
                lo = mid;
            else
                hi = mid-1;

        }
        cout << B[hi] << endl;
    }
    return 0;
}
