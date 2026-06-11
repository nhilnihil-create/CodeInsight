#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <set>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    string s, a, b;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        a += s[i];
        b += s[i+n];
    }
    reverse(b.begin(), b.end());
    map<pair<string, string>, int> v;
    for (int i = 0; i < (1 << n); ++i) {
        string k, l;
        for (int j = 0; j < n; ++j) {
            if (i & (1<<j)) k += a[j];
            else l += a[j];
        }
        v[make_pair(k, l)]++;
    }
    ll ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        string k, l;
        for (int j = 0; j < n; ++j) {
            if (i & (1<<j)) k += b[j];
            else l += b[j];
        }
        ans += v[make_pair(k, l)];
    }
    cout << ans << "\n";
    return 0;
}
