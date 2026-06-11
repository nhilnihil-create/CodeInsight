#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
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

int N, M, K, Q, W, H, L, R, C, A, B;
string S;

int main() {
    cin >> N >> A >> B;
    if (N + 1 < A + B) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    if (A >= B) {
        if (B >= ((N + A - 1) / A)) {
            int b = 0;
            int now = 1;
            while ((b + (N - b + A - 1) / A) < B) {
                ans.push_back(now);
                b++;
                now++;
            }
            int low = now - 1;
            int up = low + A;
            while (low <= N) {
                now = up;
                while (now > low) {
                    if (now > N) {
                        now--;
                        continue;
                    }
                    ans.push_back(now);
                    now--;
                }
                low = up;
                up = up + A;
            }
            reverse(ALL(ans));
        } else {
            cout << -1 << endl;
            return 0;
        }
    } else {
        if (A >= ((N + B - 1) / B)) {
            int a = 0;
            int now = N;
            while ((a + (N - a + B - 1) / B) < A) {
                ans.push_back(now);
                a++;
                now--;
            }
            int up = now + 1;
            int low = up - B;
            while (up > 0) {
                now = low;
                while (now < up) {
                    if (now <= 0) {
                        now++;
                        continue;
                    }
                    ans.push_back(now);
                    now++;
                }
                up = low;
                low = low - B;
            }
            reverse(ALL(ans));
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i];
        if (i != (int)ans.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
