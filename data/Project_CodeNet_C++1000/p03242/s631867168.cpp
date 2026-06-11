#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define nl '\n'
#define INF 1e9 + 5
#define f(i, n) for (int i = 0; i < n; ++i)

using namespace std;
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    f(i, n) {
        if (s[i] == '1')
            cout << "9";
        else if (s[i] == '9')
            cout << "1";
        else
            cout << s[i];
    }
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}