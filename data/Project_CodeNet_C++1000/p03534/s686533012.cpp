#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << (x) << '\n';
typedef int64_t Int;
Int mod = 1e9+7;
Int INF = 1e9+18;

int main() {
    ios::sync_with_stdio(false);   
    string s;
    cin >> s;
    Int n = (Int)s.size();
    Int a[3] = {};
    for (Int i = 0; i < n; i++) a[s[i] - 'a']++;
    sort(a, a + 3);
    if ((a[0] == a[1] && a[1] == a[2]) ||
        (a[0] + 1 == a[2] && a[1] == a[2]) ||
        (a[0] + 1 == a[2] && a[0] == a[1])) {
            dump("YES");
    }
    else {
        dump("NO");
    }
    return 0;
}