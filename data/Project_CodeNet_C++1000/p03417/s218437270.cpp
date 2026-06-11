#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    ll N, M;
    cin >> N >> M;
    if(N == 1 && M == 1) {
        cout << 1 << endl;
        return 0;
    }
    if(N == 1) {
        cout << M-2 << endl;
        return 0;
    }
    if(M == 1) {
        cout << N-2 << endl;
        return 0;
    }
    ll ans = (N-2) * (M-2);
    cout << ans << endl;

}