#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair < ll, ll > PLL;
#define rep(i,n) for (int i = 0; i < (n); ++i)
ll MOD = 1e9+7;
int main() {
    string s;
    cin >> s;
    int l = 0;
    int r = s.length()-1;
    bool ok = true;
    int cnt = 0;
    while (l <= r) {
        if ( s[l] == s[r] ) {
            ++l;
            --r;
            continue;
        }
        else if ( s[l] == 'x' ) {
            ++l;
            ++cnt;
            continue;
        }
        else if ( s[r] == 'x' ) {
            --r;
            ++cnt;
            continue;
        }
        else {
            ok = false;
            break;
        }
    }
    if ( !ok ) cout << -1 << endl;
    else       cout << cnt << endl;
    return 0;
}
