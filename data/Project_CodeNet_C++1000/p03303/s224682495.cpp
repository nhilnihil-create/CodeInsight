#include <bits/stdc++.h>

#define PI acos(-1)
#define all(a) a.begin(), a.end()
#define full(a, n) a, a + n
#define ma(type, size) (type *)malloc(sizeof(type) * size)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define f0n(i, n) for (i = 0; i < (n); i++)
#define f1n(i, n) for (i = 1; i <= (n); i++)
#define fab(i, a, b) for (i = (a); i <= (b); i++)
#define fr(i, b, a) for (i = (b); i >= (a); i--)

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
	tree_order_statistics_node_update> indexed_set;
//*/
typedef long long int ll;
typedef long int lo;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;

typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

//* utility function
inline bool compare(ll i, ll j)
{
    return i < j;
}
//*/

//* function prototypes
template< typename T>
T gcd(T a, T b);
//*/

//int row, column;
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
ll p2[63] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296, 8589934592, 17179869184, 34359738368, 68719476736, 137438953472, 274877906944, 549755813888, 1099511627776, 2199023255552, 4398046511104, 8796093022208, 17592186044416, 35184372088832, 70368744177664, 140737488355328, 281474976710656, 562949953421312, 1125899906842624, 2251799813685248, 4503599627370496, 9007199254740992, 18014398509481984, 36028797018963968, 72057594037927936, 144115188075855872, 288230376151711744, 576460752303423488, 1152921504606846976, 2305843009213693952, 4611686018427387904};
#ifdef DEBUG
#endif // DEBUG

int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll number_of_test_case = 1, test_case;
    //cin >> number_of_test_case;
    for (test_case = 1; test_case <= number_of_test_case; test_case++)
    {
        ll i, n;
        string s;

        cin >> s >> n;

        for(i = 0; i < s.length(); i += n)
        {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}
template< typename T>
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}
