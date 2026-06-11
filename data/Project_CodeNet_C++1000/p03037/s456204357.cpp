#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n , m;
    cin >> n >> m;

    int mx_start = -1e9 , mn_end = 1e9;
    while (m--) {
        int l , r;
        cin >> l >> r;
        mx_start = max(mx_start , l);
        mn_end = min(mn_end , r);
    }

    cout << max(0 , mn_end - mx_start + 1);
}
