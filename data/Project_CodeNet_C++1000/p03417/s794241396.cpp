#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll N, M;
    cin >> N >> M;
    ll ans;
    if (N == 1 && M == 1) ans = 1;
    else if (N == 1 || M == 1) ans = N * M - 2;
    else ans = (N - 2) * (M - 2);
    cout << ans << endl;
}
