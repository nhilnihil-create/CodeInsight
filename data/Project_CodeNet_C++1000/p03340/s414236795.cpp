#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

int d[200005][20];

int main() {
    int n;
    cin >> n;
    rep(i,n) {
        int a;
        cin >> a;
        rep(j,20) {
            d[i][j] = a%2;
            a /= 2;
        }
    }
    int l = 0, r = 0;
    vector<int> tmp(20);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int nextleft = i;
        while (l < nextleft) {
            rep(j,20) tmp[j] -= d[l][j];
            l++;
        }
        while (1) {
            if (r == n) break;
            bool ok = false;
            rep(j,20) {
                if (tmp[j] == 1 && d[r][j] == 1) ok = true;
            }
            if (ok) break;
            rep(j,20) tmp[j] += d[r][j];
            r++;
        }
        ans += r-l;
    }
    cout << ans << endl;
    return 0;
}