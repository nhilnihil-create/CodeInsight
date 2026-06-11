#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        string s = to_string(i);
        int sum = 0;
        for(auto cc : s) {
            sum += cc - 48;
        }
        if(a <= sum && sum <= b) {
            ans += i;
        }
    }
    cout << ans << "\n";
    return 0;
}