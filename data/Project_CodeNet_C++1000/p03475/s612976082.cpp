#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    vec<int> C(N - 1), S(N - 1), F(N - 1);
    rep(i, N - 1) cin >> C[i] >> S[i] >> F[i];

    rep(i, N - 1) {
        int nows = S[i] + C[i];
        for (int j = i + 1; j < N - 1; ++j) {
            if (nows >= S[j])
                nows = nows + (F[j] - ((nows) % F[j])) % F[j];
            else
                nows = S[j];
            nows += C[j];
        }
        cout << nows << endl;
    }
    cout << 0 << endl;
}