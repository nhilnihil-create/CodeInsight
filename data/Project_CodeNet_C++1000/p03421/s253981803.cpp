#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b; cin >> n >> a >> b;
    deque<int> ans;
    if ((long long) a * b < (long long) n) {
        cout << -1 << endl;
        return 0;
    }
    if (max(a, b) == n && min(a, b) != 1) {
        cout << -1 << endl;
        return 0;
    }
    if (a + b > n+1) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < b; i++) {
        ans.push_back(b-i);
    }
    a--; int cur = b; int end = n-a;
    while (a) {
        ans.push_back(n-a+1);
        int t = min(b-1, end-cur);
        while (t) {
            ans.push_back(cur+t);
            t--;
        }
        cur += min(b-1, end-cur);
        a--;
    }
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}