#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;

int n, m;
int X[N], Y[N];
ll d[N];

const int dx[5] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
const char dc[5] = {'R', 'L', 'U', 'D'};

void getp(ll x, ll y) {
    for(int i = m; i; i--) {
        int now = d[i];
        for(int j = 0; j < 4; j++) {
            ll curx = x + d[i] * dx[j], cury = y + d[i] * dy[j];
            if(abs(curx) + abs(cury) < now) {
                cout << dc[j];
                x = curx, y = cury;
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    int sign = 1, mx = 0;
    for(int i = 1; i <= n; i++) cin >> X[i] >> Y[i];
    for(int i = 2; i <= n; i++) {
        if((abs(X[i] + Y[i]) & 1) != (abs(X[i - 1] + Y[i - 1]) & 1))
            sign = 0;
        mx = max(mx, abs(X[i]) + abs(Y[i]));
    }
    if(!sign) {cout << -1; return 0;}
    for(d[m = 1] = 1; d[m] << 1 <= mx; ++m, d[m] = d[m - 1] << 1);
    if(abs(X[1] + Y[1]) & 1) sign = 0;
    cout << m + sign << '\n';
    if(sign) cout << 1 << ' ';
    for(int i = m; i; i--) cout << d[i] << " \n"[i == 1];
    for(int i = 1; i <= n; i++) {
        if(sign) cout << 'R';
        getp(X[i] - sign, Y[i]);
        cout << '\n';
    }
    return 0;
}
