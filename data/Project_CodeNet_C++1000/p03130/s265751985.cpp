#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int cnt[5] = {};
    rep(i,3) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }
    string ans = "YES";
    rep(i,5) {
        if (cnt[i] > 2) ans = "NO";  
    }
    cout << ans << endl;
}