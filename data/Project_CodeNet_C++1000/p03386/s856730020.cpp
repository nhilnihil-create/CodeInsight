#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main() {
    fastio;
    int a, b, k;
    cin >> a >> b >> k;
    set<int> ans;
    for (int i = 0; i < k; ++i) {
        if (a + i <= b)
            ans.insert(a + i);
    }
    for (int i = k-1; i >= 0; --i) {
        if (b - i >= a)
            ans.insert(b - i);
    }
    for (auto i : ans) cout << i << "\n";
    return 0;
}