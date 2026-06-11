#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (m > a[i].second) {
            m -= a[i].second;
            ans += (long long)a[i].first * a[i].second;
        }
        else if (m <= a[i].second) {
            ans += (long long)a[i].first * m;
            break;
        }
    }
    cout << ans << endl;
}