#include<bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(),(x).end()
#define int long long
 
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    int ans = 0;
    for (int i = 0; i < 29; ++i) {
        int cnt = 0;
        vector <int> b1, b2;
        for (int j = 0; j < n; ++j) {
            if((b[j] >> i) & 1) b1.push_back((b[j] & ((1 << i) - 1)));
            else b2.push_back((b[j] & ((1 << i) - 1)));
        }
        sort(all(b1));
        sort(all(b2));
        for (int j = 0; j < n; ++j) {
            int x = (a[j] & ((1 << i) - 1)); 
            if((a[j] >> i) & 1) {
                int t1 = b1.end() - lower_bound(all(b1), (1 << i) - x);
                int t2 = lower_bound(all(b2), (1 << i) - x) - b2.begin();
                cnt = (cnt + t1 + t2) & 1;
            } else {
                int t1 = lower_bound(all(b1), (1 << i) - x) - b1.begin();
                int t2 = b2.end() - lower_bound(all(b2), (1 << i) - x);
                cnt = (cnt + t1 + t2) & 1;
            }
        }
        if(cnt) ans |= (1LL << i);
    }

    cout << ans << endl;
    return 0;
}