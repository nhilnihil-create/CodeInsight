#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define nl '\n'
#define f(i, n) for (int i = 0; i < n; ++i)

using namespace std;
void solve() {
    int a, b;
    cin >> a >> b;
    bool ans = a <= 8 && b <= 8;
    cout << ((ans) ? "Yay!" : ":(") << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}