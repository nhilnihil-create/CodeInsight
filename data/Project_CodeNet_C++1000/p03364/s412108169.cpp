//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int n;
    cin >> n;
    vs s(n);
    rep(i, n) {
        cin >> s[i];
    }

    int ans = 0;
    rep(i_, n) {
        bool x = true;
        rep(i, n) {
            rep(j, i) {
                if(s[(i + i_)%n][j] != s[(j + i_)%n][i]) {
                    x = false;
                    break;
                }
            }
            if(!x) break;
        }
        if(x) ++ans;
    }

    cout << ans*n << endl;
}