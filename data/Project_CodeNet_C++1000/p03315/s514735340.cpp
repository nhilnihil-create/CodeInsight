#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    string s; cin >> s;
    ll ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '+') ans++;
        else ans--;
    }
    cout << ans << endl;
}