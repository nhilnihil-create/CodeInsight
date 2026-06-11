#include <bits/stdc++.h>
using namespace std;

#define DEBUG

#ifdef DEBUG
#define dump(x) cout << "[*] " #x ": " << x << endl
#define debug(x) x
#else
#define dump(x)
#define debug(x)
#endif

//#define int long long
typedef long long ll;
//constexpr int INF = 1e9;
//constexpr int MOD = 1000000007;

decltype(1) main() {
    //cin.tie(nullptr);
    //ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    for (char& c : s) {
        cout << (c == '1' ? '9' : '1');
    }
    cout << endl;
    return 0;
}
