#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 1000000;

int main() {
    int N;
    ll a[200005];
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    ll r = 0, ans = 0, sum1 = 0, sum2 = 0;
    for (int i = 1; i <= N; i++) {
        while (sum1==sum2 && r <= N) {
            r++;
            sum1 += a[r];
            sum2 ^= a[r];
        }
        ans += r-i;
        sum1 -= a[i];
        sum2 ^= a[i];
    }
    cout << ans << endl;
}
