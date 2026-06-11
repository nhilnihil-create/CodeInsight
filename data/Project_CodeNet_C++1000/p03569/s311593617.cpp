#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
typedef long long int64;

int main() {
    string S;  cin >> S;
    int ans = 0;
    int l = 0, r = S.size() - 1;
    while(l < r) {
        if(S[l] == S[r]) {
            ++l, --r;
        } else if(S[l] == 'x') {
            ++l, ++ans;
        } else if(S[r] == 'x') {
            --r, ++ans;
        } else {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << ans << '\n';
    return 0;
}
