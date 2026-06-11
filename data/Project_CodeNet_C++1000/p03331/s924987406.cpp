#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int solve(int k) {
    int sum = 0;
    while (k) {
        sum += k % 10;
        k /= 10;
    }
    return sum;
}
int main() {
    int n;
    cin >> n;
    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        ans = min(ans, solve(i) + solve(n - i));
    }
    cout << ans << endl;
}
