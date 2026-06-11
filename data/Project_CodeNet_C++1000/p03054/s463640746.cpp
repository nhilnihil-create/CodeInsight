#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    ll h, w;
    cin >> h >> w >> n;
    ll x, y;
    cin >> y >> x;
    string s, t;
    cin >> s;
    cin >> t;
    ll xR, xL, yU, yD;
    xR = xL = x;
    yU = yD = y;
    bool flag = false;
    for(i = 0; i < n; i++) {
        if(s[i] == 'U') yU--;
        if(s[i] == 'D') yD++;
        if(s[i] == 'L') xL--;
        if(s[i] == 'R') xR++;
        if(xL < 1) {
            flag = true;
        }
        if(xR > w) {
            flag = true;
        }
        if(yU < 1) {
            flag = true;
        }
        if(yD > h) {
            flag = true;
        }
        if(t[i] == 'U' && yD > 1) yD--;
        if(t[i] == 'D' && yU < h) yU++;
        if(t[i] == 'L' && xR > 1) xR--;
        if(t[i] == 'R' && xL < w) xL++;
        if(flag) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}