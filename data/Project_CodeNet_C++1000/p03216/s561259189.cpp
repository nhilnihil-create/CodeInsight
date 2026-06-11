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

ll N, Q;
string S;

int main() {
    cin >> N >> S >> Q;
    vector<ll> k(Q);
    for (int i = 0; i < Q; i++) {
        cin >> k.at(i);
    }

    vector<ll> ans(Q);
    for (int q = 0; q < Q; q++) {
        ll p = 0;
        ll m = 0;
        ll c = 0;
        for (int i = 1; i < k[q]; i++) {
            if (S[i] == 'M') {
                m++;
            } else if (S[i] == 'C') {
                p += m;
                c++;
            }
        }
        ll sum = 0;
        //cout << "k i m c p" << endl;
        for (int i = 0; i < N - 2; i++) {
            //cout << k[q] << " " << i << " " << m << " " << c << " " << p << endl;
            if (S[i] == 'D') sum += p;

            if (S[i + 1] == 'M') {
                p -= c;
                m--;
            } else if (S[i + 1] == 'C') {
                c--;
            }

            if (i + k[q] < N) {
                if (S[i + k[q]] == 'M') {
                    m++;
                } else if (S[i + k[q]] == 'C') {
                    p += m;
                    c++;
                }
            }
        }
        ans[q] = sum;
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
