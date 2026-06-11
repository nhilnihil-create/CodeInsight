#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ull x;
    cin >> n >> x;
    vector<ull> v(n), sumv(n + 1, 0);
    ull ans = x * n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ans += v[i] * 5;
        sumv[i + 1] = sumv[i] + v[i];
    }

    ull hoge = x * ((n + 1) / 2);
    for (int i = 1; i <= (n + 1) / 2; i++) {
        int num = 0;
        ull sum = x * i;
        for (int j = n - 1 - i; j >= 0; j -= i) {
            sum += (sumv[j + 1] - sumv[max(j + 1 - i, 0)]) * num * 2;
            num++;
        }
        hoge = min(hoge, sum);
    }
    ans += hoge;
    cout << ans << endl;
    return 0;
}