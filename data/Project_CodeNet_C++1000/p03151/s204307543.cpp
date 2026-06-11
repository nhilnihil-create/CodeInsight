#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n;
    cin >> n;

    vector<ll> a(n), b(n), diff(n);
    ll sum_a = 0, sum_b = 0, need = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum_a += a[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        sum_b += b[i];
        diff[i] = a[i] - b[i];
        if (diff[i] < 0) {
            need -= diff[i];
            ans++;
        }
    }

    if (sum_a < sum_b) {
        cout << -1 << endl;
        return 0;
    }

    sort(diff.begin(), diff.end(), greater<ll>());
    int idx = 0;
    while(need > 0) {
        need -= diff[idx];
        ans++;
        idx++;
    }

    cout << ans << endl;
}