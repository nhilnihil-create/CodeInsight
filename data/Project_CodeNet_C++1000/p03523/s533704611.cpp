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
    string S;
    cin >> S;
    int N = S.size();
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'A') cnt++;
    }

    if (cnt >= 5) {
        cout << "NO" << endl;
        return 0;
    } else {
        for (int i = 0; i <= N; i++) {
            for (int j = i; j <= N + 1; j++) {
                for (int k = j; k <= N + 2; k++) {
                    for (int l = k; l <= N + 3; l++) {
                        string tmp = S;
                        if (cnt <= 3) {
                            tmp.insert(i, "A");
                            if (cnt <= 2) {
                                tmp.insert(j, "A");
                                if (cnt <= 1) {
                                    tmp.insert(k, "A");
                                    if (cnt <= 0) {
                                        tmp.insert(l, "A");
                                    }
                                }
                            }
                        }
                        if (tmp == "AKIHABARA") {
                            cout << "YES" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}
