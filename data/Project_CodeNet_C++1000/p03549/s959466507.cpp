#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    int N, M; cin >> N >> M;
    int t = pow(2, M);
    int ans = ((N - M) * 100 + M * 1900) * t;
    cout << ans << endl;
    return 0;
}