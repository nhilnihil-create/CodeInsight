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
    int n;
    cin >> n;
    int il(0), ir(n);
    string l, r, curr;
    cout << 0 << endl;
    cin >> curr;
    r = l = curr;
    if (l == "Vacant")
        return 0;
    for (int i = 0; i < 20; ++i) {
        int mid = (il + ir) / 2;
        cout << mid << endl;
        cin >> curr;
        if (curr == "Vacant")
            return 0;

        if ((curr != l && (mid - il) % 2 == 0) || (curr == l && (mid - il) % 2 == 1)) {
            ir = mid;
            r  = curr;
        } else if ((curr != r && (ir - mid) % 2 == 0) || (curr == r && (ir - mid) % 2 == 1)) {
            il = mid;
            l  = curr;
        }
    }
    return 0;
}