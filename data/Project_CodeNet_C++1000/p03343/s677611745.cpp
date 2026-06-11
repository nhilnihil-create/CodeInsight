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
// 1次元 vector
template <class T>
ostream &operator<<(ostream &s, vector<T> vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        if (i > 0) {
            s << " ";
        }
        s << vec[i];
    }
    return s << endl;
}
using ll = long long;
using ull = unsigned long long;
const int INF = 2100100100;
// const int MOD = 1e9 + 7;

struct Range {
    vector<int> val;
    Range();
    Range(const vector<int> &a, int l, int r) {
        for (int i = l; i < r; i++) {
            val.push_back(a[i]);
        }
    }
};

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<int> S = A;
    sort(ALL(S));

    vector<Range> ranges;
    ranges.push_back(Range(A, 0, N));
    int ans = INF;
    for (int yid = 0; yid < N; yid++) {
        int Y = S[yid];

        vector<Range> next;
        for (auto range : ranges) {
            int now = 0;
            for (int i = 0; i < (int)range.val.size(); i++) {
                if (range.val[i] < Y) {
                    //cout << Range(range.val, now, i).val;
                    if (now != i) next.push_back(Range(range.val, now, i));
                    now = i + 1;
                }
            }
            if (now != (int)range.val.size()) next.push_back(Range(range.val, now, (int)range.val.size()));
        }
        ranges = next;

        vector<int> can;
        for (auto range : ranges) {
            sort(ALL(range.val));
            for (int i = 0; i < (int)range.val.size() - K + 1; i++) {
                can.push_back(range.val[i]);
            }
        }
        sort(ALL(can));
        if ((int)can.size() >= Q) {
            //cout << can[Q - 1] << " " << Y << endl;
            chmin(ans, can[Q - 1] - Y);
        }
    }
    cout << ans << endl;
}
