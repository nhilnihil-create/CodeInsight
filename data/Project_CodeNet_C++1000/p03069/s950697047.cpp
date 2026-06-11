#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector <int> pref(n + 1);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + (s[i] == '#');

    int ans = 1e9;
    for (int i = 0; i <= n; ++i) {
        ans = min(ans, pref[i] + (n - i - (pref[n] - pref[i])));
    }           
    cout << ans << endl;
}