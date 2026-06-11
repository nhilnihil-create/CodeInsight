#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a(100001, 0), b(100001, 0);
    int v;
    for (int i = 0; i < n; ++i) {
        cin >> v;
        if (i & 1) a[v]++;
        else b[v]++;
    }

    int ans;
    int am = max_element(a.begin(), a.end()) - a.begin();
    int bm = max_element(b.begin(), b.end()) - b.begin();
    if (am != bm) ans = n - a[am] - b[bm];
    else {
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        ans = min(n - a[0] - b[1], n - a[1] - b[0]);
    }
    cout << ans << "\n";
}