#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    if(!n) {
        cout << 0;
    }
    vector<bool> ans;
    while(n != 0) {
        if(n & 1) {
            ans.push_back(1);
            n--;
        }
        else {
            ans.push_back(0);
        }
        n /= -2;
    }
    for (int i = (int) ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
