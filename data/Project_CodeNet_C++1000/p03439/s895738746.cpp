#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
int main() {
    int n;
    cin >> n;
    int ok = 0, ng = n - 1, mid;
    string zero;
    cout << 0 << endl;
    cin >> zero;
    if (zero == "Vacant") return 0;
    while (ng - ok > 1) {
        mid = (ng + ok) / 2;
        cout << mid << endl;
        string now;
        cin >> now;
        if (now == "Vacant") return 0;

        ((mid % 2 == 0 && now == zero) || (mid % 2 == 1 && now != zero) ? ok
                                                                        : ng) =
            mid;
    }
    cout << ng << endl;
}