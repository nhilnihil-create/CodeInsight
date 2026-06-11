#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
int n, m, k;
ll ans;
string s;
//  M, A, R, C or H.
int a[5];
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s[0] == 'M')
            ++a[0];
        else if (s[0] == 'A')
            ++a[1];
        else if (s[0] == 'R')
            ++a[2];
        else if (s[0] == 'C')
            ++a[3];
        else if (s[0] == 'H')
            ++a[4];
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            for (int l = j + 1; l < 5; ++l) {
                ans += 1LL * a[i] * a[j] * a[l];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
