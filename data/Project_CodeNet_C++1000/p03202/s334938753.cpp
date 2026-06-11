#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    auto chk = [&](int x) {
        map<int, int> mp;
        for (int i = 2; i <= n; i++) if (a[i - 1] >= a[i]) {
            if (x == 1) return 0;
            while (!mp.empty()) {
                int mx = mp.rbegin()->first;
                if (mx > a[i]) mp.erase(mx);
                else break;
            }
            int j = a[i];
            while (j && mp[j] + 1 == x) mp.erase(j), j--;
            if (!j) return 0; mp[j]++;
        }
        return 1;
    };
    int l = 1, r = n, ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (chk(mid)) r = (ans = mid) - 1;
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}