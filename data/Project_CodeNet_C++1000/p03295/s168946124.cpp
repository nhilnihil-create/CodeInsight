#include <bits/stdc++.h>
using namespace std;
#define pair pair<int, int>
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair> a(m);
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        a[i].first = y;
        a[i].second = x;
    }
    sort(a.begin(),a.end());
    int ans = 0, d = 0;
    for(int i=0; i<m; i++) {
        if(d <= a[i].second) {
            ans++;
            d = a[i].first;
        }
    }
    cout << ans << endl;
}