#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    sort(a, a + n);

    int maxv = *max_element(a, a + n);
    int half = maxv / 2;
    int back = lower_bound(a, a + n, half) - a;
    int front = back - 1;

    int r = back;
    if (abs(a[back] - half) > abs(a[front] - half) || back == n - 1) r = front;

    cout << maxv << ' ' << a[r] << endl;

    return 0;
}
