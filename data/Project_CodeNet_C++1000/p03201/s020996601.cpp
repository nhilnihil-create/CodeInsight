#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn];
unordered_map<int, int> mp;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; mp[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = n; i; i--) if (mp[a[i]]) {
        mp[a[i]]--;
        for (long long j = 1; j <= 2e9; j *= 2) {
            if (j > a[i] && mp[j - a[i]]) {
                mp[j - a[i]]--, ans++; break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}