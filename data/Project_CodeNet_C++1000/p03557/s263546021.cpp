#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int lb(vector<int> a, int key) {
    int l = -1, r = (int)a.size();
    while(r - l > 1) {
        int mid = (l+r)/2;
        if (a[mid] >= key) r = mid; 
        else l = mid;
    }
    return r;
}
int ub(vector<int> a, int key) {
    int l = -1, r = (int)a.size();
    while(r - l > 1) {
        int mid = (l+r)/2;
        if (a[mid] > key) r = mid; 
        else l = mid;
    }
    return r;
}
int main() {
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll na = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        ll nc = n - (upper_bound(c.begin(), c.end(), b[i]) - c.begin());
        ans += nc*na;
    }
    cout << ans << endl;
}
