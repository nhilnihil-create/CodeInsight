#include<bits/stdc++.h>
#define int int64_t
using namespace std;

int bit[(int)2e5+5];

void update(int idx , int val , int n) {
    for(; idx <= n; idx += (idx & (-idx))) {
        bit[idx] = max(bit[idx] , val);
    }
}

int get(int idx) {
    int ans = 0;
    for(; idx > 0; idx -= (idx & -idx)) ans = max(ans , bit[idx]);
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n , ans = 0;
    cin >> n;
    int h[n] , a[n];
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        int val = get(h[i]-1) + a[i];
        update(h[i] , val , n);
        ans = max(ans , val);
    }
    cout << ans << "\n";
    
    return 0;
}

