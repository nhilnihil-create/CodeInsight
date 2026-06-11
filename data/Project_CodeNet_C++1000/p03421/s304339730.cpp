#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    if (a + b - 1 > n) {
        cout << -1 << "\n";
        return 0;
    }
    if (a * b < n) {
        cout << -1 << "\n";
        return 0;
    }
    vl arr;
    arr.reserve(n);
    ll val    = 0;
    ll to_add = n - b + 1;
    ll lastb   = 0;
    for (int i = 0; i < to_add; ++i) {
        arr.push_back(val++);
        if (i % a == a - 1) {
            lastb = val - 1;
            val -= 2 * a;
            if (i != a - 1)
            to_add++;
        }
    }
    for (int i = 0; i < n - to_add; ++i) {
        lastb -= a;
        arr.push_back(lastb);
    }
    vl sorted = arr;
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; ++i) {
        cout << 1 + lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin() << " ";
    }
    cout << endl;
    return 0;
}