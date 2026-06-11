#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, M;
    cin >> N >> M;

    int ans;
    ans = M * 1900 + (N-M) * 100;
    rep(i, M) ans *= 2;

    cout << ans << endl;

    return 0;
}