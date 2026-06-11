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
template <class T>
ostream &operator<<(ostream &s, vector<T> vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        if (i > 0) {
            s << ' ';
        }
        s << vec[i];
    }
    return s << endl;
}

int main() {
    int H, W, D;
    cin >> H >> W >> D;
    auto A = make_vec<int>(H, W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    int Q;
    cin >> Q;
    vector<int> L(Q), R(Q);
    for (int i = 0; i < Q; i++) {
        cin >> L.at(i) >> R.at(i);
    }

    using P = pair<int, int>;
    vector<vector<P>> Cor = make_vec<P>(D, H * W / D + 2);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            Cor[A[i][j] % D][A[i][j] / D] = make_pair(i, j);
        }
    }

    vector<vector<int>> S;
    for (auto C : Cor) {
        vector<int> sum((int)C.size());
        for (int i = 0; i < (int)C.size() - 1; i++) {
            P p1 = C[i];
            P p2 = C[i + 1];
            sum[i + 1] += sum[i] + abs(p2.first - p1.first) + abs(p2.second - p1.second);
        }
        S.push_back(sum);
    }

    /*
    for (int i = 0; i < D; i++) {
        cerr << S[i];
    }
*/
    for (int i = 0; i < Q; i++) {
        int d = L[i] % D;
        cout << S[d][R[i] / D] - S[d][L[i] / D] << "\n";
    }
}
