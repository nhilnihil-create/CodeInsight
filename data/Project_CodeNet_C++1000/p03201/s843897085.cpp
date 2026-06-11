#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n;
int a[N];
ll pw2[35];
map <int, int> mp;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], mp[a[i]]++;
    sort(a + 1, a + n + 1);
    pw2[0] = 1;
    for(int i = 1; i < 32; i++) pw2[i] = 2ll * pw2[i - 1];
    int ans = 0;
    for(int i = n; i >= 1; i--) {
        if(mp[a[i]]) {
            int p = lower_bound(pw2, pw2 + 32, a[i]) - pw2;
            if(a[i] == pw2[p]) ++p;
            --mp[a[i]];
            if(mp[pw2[p] - a[i]]) {
                --mp[pw2[p] - a[i]];
                ++ans;
            }
        }
    }
    cout << ans;
    return 0;
}
