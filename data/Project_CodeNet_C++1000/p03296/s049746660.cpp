#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int counter = 0, cur = a[0];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == cur) {
            counter++;
        } else {
            if(counter % 2 == 0) {
                ans += counter / 2;
            } else {
                ans += (counter - 1) / 2;
            }
            cur = a[i];
            counter = 1;
        }
    }
    if(counter % 2 == 0) {
        ans += counter / 2;
    } else {
        ans += (counter - 1) / 2;
    }
    cout << ans << "\n";
    return 0;
}