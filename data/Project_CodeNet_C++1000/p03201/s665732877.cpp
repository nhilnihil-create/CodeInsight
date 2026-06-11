#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        m[a]++;
    }

    int ans = 0;
    for (auto i = m.rbegin(); i != m.rend(); i++) {
        int x = 1 << (int)floor(log2((double)2 * (i -> first)));
        if (i -> first == x - i -> first) {
            ans += (i -> second) / 2;
            continue;
        }
        
        int c = min(i -> second, m[x - i -> first]);
        ans += c;
        m[x - i -> first] -= c;
    }
    cout << ans << endl;
}