#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <complex>
#include <bitset>
#include <functional>

using namespace std;
using ll=long long int;

template<typename M, typename N>
constexpr common_type_t<M, N> gcd(M a, N b) {
    return b ? gcd(b, a%b) : abs(a);
}

bool solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < b) return false;
    if (d < b) return false;
    if (c >= b-1) return true;

    ll ra = a % b;
    ll step = gcd(d, b);
    ll cs = (c - ra + b) % step;

    return b <= step - cs + c;
}

int main() {
    ll t;
    cin >> t;
    while (t--) cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
