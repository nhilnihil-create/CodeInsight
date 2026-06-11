#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using ll = unsigned long long int;
using namespace std;

int main() {
    fastIO;
    int n, a, b;
    cin >> n >> a >> b;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int sub_sum = 0;
        int t = i;
        while (t > 0) {
            sub_sum += t % 10;
            t /= 10;
        }
        if (a <= sub_sum && sub_sum <= b)
            sum += i;
    }
    cout << sum << endl;
}