#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<int> C(N-1), S(N-1), F(N-1);
    rep(i,N-1) cin >> C.at(i) >> S.at(i) >> F.at(i);
    for (int i = 0; i < N; ++i) {
        if (i == N - 1) {
            cout << 0 << endl;
        } else {
            int ans = 0;
            for (int j = i; j < N - 1; ++j) {
                if (ans >= S.at(j)) ans += (F.at(j) - ans % F.at(j)) % F.at(j) + C.at(j);
                else ans = S.at(j) + C.at(j);
            }
            cout << ans << endl;
        }
    }
}
