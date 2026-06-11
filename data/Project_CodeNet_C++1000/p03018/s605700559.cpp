#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s; cin >> s;
    int A = 0;
    ll ans = 0;
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == 'A') {
            A++;
        } else if (s[i] == 'B' && s[i+1] == 'C') {
            ans += A;
            i++;
        } else {
            A = 0;
        }
    }
    cout << ans << endl;
}
