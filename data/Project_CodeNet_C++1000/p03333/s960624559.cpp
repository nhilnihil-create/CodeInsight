#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, s1[maxn], s2[maxn];

int main() {
    cin >> n;
    for (int i = 1, l, r; i <= n; i++) {
        cin >> l >> r;
        l += 100001, r += 100001;
        s1[r]++, s2[l]++;
    }
    s1[100001]++, s2[100001]++;
    for (int i = 1; i <= 200005; i++) {
        s1[i] += s1[i - 1];
    }
    for (int i = 200005; i; i--) {
        s2[i] += s2[i + 1];
    }
    long long ans = 0;
    for (int i = 1; i <= 200005; i++) {
        ans += min(s1[i], s2[i + 1]);
    }
    cout << ans * 2 << endl;
    return 0;
}