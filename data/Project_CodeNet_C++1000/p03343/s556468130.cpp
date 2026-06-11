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
const int INF = 2100100100;
const int MOD = 1e9 + 7;

int N, M, K, Q;
string S;

struct Range {
    int len;
    vector<ll> val;
    Range(const vector<ll> &val_, int l, int r) : len(r - l) {
        val.resize(len);
        for (int i = 0; i < len; i++) {
            val[i] = val_[i + l];
        }
    }
};

int main() {
    cin >> N >> K >> Q;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    B = A;
    sort(ALL(B));

    vector<Range> ranges;
    ranges.push_back(Range(A, 0, N));

    ll ans = INF;
    for (int i = 0; i < N; i++) {
        if (i + Q - 1 > N) break;
        ll first = B[i];
        ll qth = B[i + Q - 1];
        //debug(first);
        //debug(qth);
        vector<Range> new_ranges;
        for (auto range : ranges) {
            int r = 0;
            for (int l = 0; l < range.len;) {
                while (r < range.len && range.val[r] >= first) {
                    r++;
                }
                if (l == r) {
                    l++;
                    r++;
                    continue;
                }
                new_ranges.push_back(Range(range.val, l, r));
                r++;
                l = r;
            }
        }
        //debug(new_ranges.size());
        int sum = 0;
        for (auto range : new_ranges) {
            int cnt = 0;
            for (auto v : range.val) {
                if (v <= qth) {
                    cnt++;
                }
            }
            //debug(cnt);
            sum += max(min(range.len - K + 1, cnt), 0);
        }
        //debug(sum);
        if (sum >= Q) {
            chmin(ans, qth - first);
        }
        ranges = new_ranges;
    }
    cout << ans << endl;
    return 0;
}
