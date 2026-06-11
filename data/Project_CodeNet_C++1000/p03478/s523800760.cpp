#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    ll N, A, B;
    cin >> N >> A >> B;

    int ans = 0;

    for (int i = 1; i <= N; ++i) {
        int sum = 0;
        int M = i;
        while (M > 0) {
            sum += M % 10;
            M /= 10;
        }
        if (sum >= A && sum <= B) ans += i;
    }
    cout << ans << endl;

}