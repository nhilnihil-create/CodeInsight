#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;

    int s[10][10];
    vector<int> s_count(m);
    rep(i,m) {
        cin >> s_count[i];

        rep(j,s_count[i]) {
            cin >> s[i][j];
            s[i][j]--; 
        }
    }

    vector<int> p(m);
    rep(i,m) cin >> p[i];


    int ans = 0;
    rep(i,1<<n) {
        bool ok = true;
        rep(j,m) {

            int count = 0;
            rep(k,s_count[j]) {
                if (i>>s[j][k] & 1) {
                    count++;
                }
            }
            if (count % 2 != p[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}