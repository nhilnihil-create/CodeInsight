#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, h; cin >> n >> h;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int max_a = *max_element(a.begin(), a.end());
    sort(b.begin(), b.end());
    int tot_b = 0;
    int ans = 1001001010;
    for (int i = 1; i <= n; i++) {
        int num = i;
        tot_b += b[n-i];
        int tmp_h = h - tot_b;
        if (tmp_h > 0)
            num += ceil((double)tmp_h / (double)max_a);
        ans = min(ans, num);
    }
    cout << ans << endl;
}
