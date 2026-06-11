#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000009;
const long long INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    vector<int> vx(N);
    vector<int> vy(N);
    vector<int> vh(N);
    int si = -1;
    for (int i = 0; i < N; ++i) {
        cin >> vx[i] >> vy[i] >> vh[i];
        if (vh[i] > 0) si = i;
    }
    ll resx = -1, resy = -1, resh = -1;
    for (int x = 0; x <= 100; ++x) {
        for (int y = 0; y <= 100; ++y) {
            ll h = vh[si] + abs(x - vx[si]) + abs(y - vy[si]);
            bool ok = true;
            for (int i = 0; i < N; ++i) {
                if (vh[i] > 0 && h - vh[i] != abs(x - vx[i]) + abs(y - vy[i])) ok = false;
                if (vh[i] == 0 && h > abs(x - vx[i]) + abs(y - vy[i])) ok = false;
            }
            if (ok) resx = x, resy = y, resh = h;
        }
    }
    cout << resx << " " << resy << " " << resh << endl;
    return 0;
}