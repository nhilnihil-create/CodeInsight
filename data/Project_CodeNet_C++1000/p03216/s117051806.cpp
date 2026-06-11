#include <bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    rep(_, q) {
        int k; cin >> k;
        ll d = 0;
        ll m = 0;
        ll dm = 0;
        ll dmc = 0;
        rep(i, n) {
            if (i < k-1) {
                if (s[i] == 'D') {
                    ++d;
                } else if (s[i] == 'M') {
                    ++m;
                    dm += d;
                } else if (s[i] == 'C') {
                    dmc += dm;
                }
            } else {
                if (s[i] == 'D') {
                    ++d;
                } else if (s[i] == 'M') {
                    ++m;
                    dm += d;
                } else if (s[i] == 'C') {
                    dmc += dm;
                }

                if (s[i-k+1] == 'D') {
                    dm -= m;
                    --d;
                } else if (s[i-k+1] == 'M') {
                    --m;
                }
            }
        }
        cout << dmc << endl;
    }

    return 0;
}


    
