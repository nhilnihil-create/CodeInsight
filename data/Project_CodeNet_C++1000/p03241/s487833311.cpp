#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MN = 1e5 + 5;
int N, M;

bool works(ll x) {
    ll sum = x * N;
    return sum <= M && (M - sum) % x == 0; 
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    int ans = 1;
    for (int i = 1; i <= sqrt(M); i++) {
        if (M % i == 0) {
            int j = M / i;
            if (works(i)) ans = max(ans, i);
            if (works(j)) ans = max(ans, j);
        }
    }
    cout << ans << '\n';
    return 0;
}