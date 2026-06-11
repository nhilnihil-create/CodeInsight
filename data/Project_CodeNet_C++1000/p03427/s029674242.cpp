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
    ++n;
    string s = to_string(n);
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= '1') {
            int nn = 0;
            for (int j = 0; j < i; ++j)
                nn += s[j] - '0';
            nn += s[i] - '0' - 1;
            for (int j = i + 1; j < s.size(); ++j)
                nn += 9;
            ans = max(ans, nn);
        }   
    }   
    cout << ans << endl;
}