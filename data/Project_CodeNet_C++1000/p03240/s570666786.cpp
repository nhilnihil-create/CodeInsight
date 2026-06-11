#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n), h(n);
    rep(i, n) {
        cin >> x[i] >> y[i] >> h[i];
    }
    for (int cy = 0; cy <= 100; cy++) {
        for (int cx = 0; cx <= 100; cx++) {
            int needH = -1;
            rep(i, n) {
                if (h[i] > 0) {
                    int tmp = h[i] + abs(cy - y[i]) + abs(cx - x[i]);
                    if (needH == -1) needH = tmp;
                    else {
                        if (needH != tmp) {
                            needH = -2;
                            break;
                        }
                    }
                }
            }
            if (needH == -2) continue;
            rep(i, n) {
                if (h[i] == 0) {
                    int dist = abs(cy - y[i]) + abs(cx - x[i]);
                    if (needH > dist) {
                        needH = -2;
                        break;
                    }
                }
            }
            if (needH == -2) continue;
            printf("%d %d %d\n", cx, cy, needH);
            return 0;
        }
    }
    return 0;
}