#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;

ll cal(ll k){
    ll sum = 0;
    for (ll i = 1; i <= k; ++i)
    {
        sum += i;
    }
    if(k <= 0) return 0;
    else return sum;
}

int main() {

    int h,w; cin >> h >> w;
    vector<string> s(h);
    int count = 0;
    rep(i,h) cin >> s[i];

    rep(i,h){
        rep(j,w){
            if(s[i][j] == '.') {
                count = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (i + x >= 0 && i + x <= h - 1 && j + y >= 0 && j + y <= w - 1) {
                            if (!(x == 0 && y == 0)) {
                                if (s[i + x][j + y] == '#') {
                                    count++;
                                }
                            }
                        }
                    }
                }
                s[i][j] = ('0' + count);
            }
        }
    }

    rep(i,h) {
        rep(j, w) {
            cout << s[i][j];
        }
        cout << endl;
    }
    return 0;
}









