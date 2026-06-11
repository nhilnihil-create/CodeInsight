#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int ans = 0;
    int active = 0;
    for(int i = 0; i < n; i++) {
        if(active >= h[i]) {
            active = h[i];
        } else {
            ans += h[i] - active;
            active = h[i];
        }
    }
    cout << ans << "\n";
    return 0;
}