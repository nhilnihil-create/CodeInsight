#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <assert.h>
#include <numeric>
#include <math.h>
#include <climits>
#include <stack>
#include <iomanip>
#include <sstream>

using namespace std;

template <typename T>
inline bool sign(T A) {
    return (A>0)-(A<0);
}
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SREP(i,s,n) for(int i=s; (n-i)*sign(n-s)>0; i+=sign(n-s))
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
T gcd(T a, T b) {
    if(a < b) gcd(b, a);
    if (b == 1) return 1;
    T r;
    while ((r=a%b)) {
        a = b;
        b = r;
    }
    return b;
}

bool _less(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

template <template<class,class,class...> class C, typename K, typename V, typename... Args>
V map_get(const C<K,V,Args...>& m, K const& key, const V & defval)
{
    typename C<K,V,Args...>::const_iterator it = m.find( key );
    if (it == m.end())
        return defval;
    return it->second;
}

#define MOD (1'000'000'000 + 7)



int main(void)
{
    ll K;
    cin >> K;
    vector<ll> A(K);
    REP(i, K) {
        cin >> A[i];
    }
    ll l = 2;
    ll u = 2;
    REP(i, K) {
        ll j = K - 1 - i;
        ll a = A[j];
        l = (l + a - 1) / a * a;
        u = u / a * a + a - 1;
    }
    if (l > u)
        cout << -1 << endl;
    else
        cout << l << ' ' << u << endl;
}
