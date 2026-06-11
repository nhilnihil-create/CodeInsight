#include <bits/stdc++.h>

using namespace std;

#define int long long

const int SIZE = 21;

void unplus(vector<int> &a, vector<int> b){
    for (int i = 0; i < SIZE;++ i) {
        a[i] -= b[i];
    }
}
void pl(vector<int> &a, vector<int> b){
    for (int i = 0; i < SIZE;++ i) {
        a[i] += b[i];
    }
}
bool f (vector<int> a) {
    for (int i = 0; i < SIZE; ++ i) {
        if (a[i]== 2) return true;
    }
    return false;
}


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (SIZE));
    for (int i = 0; i < n; ++ i) {
        int x;
        cin >> x;
        for (int j = 0; j < SIZE; ++ j) {
            a[i][j] = x % 2;
            x /= 2;
        }

    }
    vector<int> tmp = a[0];
    int l = 0, r= 0, ans = 0;
    while (r < n) {
        if (f(tmp)) {
            unplus(tmp, a[l]);
            l++;
            continue;
        }
        ans += (r - l + 1);
        r++;
        if (r < n) pl(tmp, a[r]);
    }
    cout << ans;
}

signed main() {
    //freopen
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}