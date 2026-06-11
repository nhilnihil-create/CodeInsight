#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<int> flag(101);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int d;
        cin >> d;
        flag[d] = 1;
    }

    int ans = 0;
    for(int i = 0; i < 101; i++) {
        ans += flag[i];
    }

    cout << ans << endl;

    return 0;
}