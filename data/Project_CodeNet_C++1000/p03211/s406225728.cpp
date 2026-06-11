#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(it) it.begin(), it.end()
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORU(i, a, b, s) for(int i = a; i < b; i += s)
#define FORD(i, a, b, s) for(int i = a; i > b; i -= s)
#define endl "\n"

ll INF = 2e18;
ll MOD = 1e9 + 7;
int i, j, k, t;

int main() {
    string s;
    cin >> s;
    int N = s.size();

    int ans = 999;
    FOR(i, N - 2) { ans = min(ans, abs(753 - atoi(s.substr(i, 3).c_str()))); }
    cout << ans << endl;
}