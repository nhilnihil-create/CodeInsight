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

int a[100][3];

int main() {
    int n;
    cin >> n;
    rep(i,n) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            int h = 0;
            bool ok = true;
            rep(i,n) {
                if (a[i][2] == 0) continue;
                int now = a[i][2] + abs(a[i][0]-cx) + abs(a[i][1]-cy);
                if (h == 0) {
                    h = now;
                    continue;
                }
                if (h != now) ok = false;
            }
            if (!ok) continue;
            rep(i,n) {
                int now = max(h - abs(a[i][0]-cx) - abs(a[i][1]-cy), 0);
                if (now != a[i][2]) ok = false;
            }
            if (ok) {
                cout << cx << " " << cy << " " << h << endl;
                return 0;
            }
        }
    }
    return 0;
}