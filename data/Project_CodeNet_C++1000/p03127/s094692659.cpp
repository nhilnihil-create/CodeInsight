#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &x : A) cin >> x;

    int ans = A.at(0);
    for (int i = 1; i < N; ++i) {
        ans = __gcd(ans, A.at(i));
    }

    cout << ans << endl;

    return 0;
}