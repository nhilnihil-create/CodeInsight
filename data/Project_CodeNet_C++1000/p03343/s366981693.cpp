#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 1e9;
// const int MOD = 1e9 + 7;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<int> S = A;
    sort(ALL(S));

    vector<vector<int>> ranges;
    ranges.push_back(A);
    int ans = INF;
    for (int i = 0; i < N; i++) {
        int min_a = S[i];
        vector<vector<int>> new_ranges;
        for (auto range : ranges) {
            int n = (int)range.size();
            for (int l = 0; l < n; l++) {
                int r = l;
                for (; r < n && range[r] >= min_a; r++) {};
                if (r == l) { continue; }
                vector<int> new_range;
                for (int j = l; j < r; j++) {
                    new_range.push_back(range[j]);
                }
                new_ranges.push_back(new_range);
                l = r - 1;
            }
        }
        ranges = new_ranges;

        vector<int> tmp;
        for (auto range : ranges) {
            int n = (int)range.size();
            sort(ALL(range));
            for (int j = 0; j < n - K + 1; j++) {
                tmp.push_back(range[j]);
            }
        }
        sort(ALL(tmp));
        if ((int)tmp.size() >= Q) chmin(ans, tmp[Q - 1] - min_a);
    }
    cout << ans << endl;
}
