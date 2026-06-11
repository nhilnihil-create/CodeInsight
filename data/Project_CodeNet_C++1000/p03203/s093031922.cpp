#include <bits/stdc++.h>

using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// cout << fixed << setprecision(20);

int H, W, N;
priority_queue<int, vector<int>, greater<int>> pq[220000];

signed main() {
    cin >> W >> H >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        pq[y].push(x);
    }
    for (int i = 1; i <= H; i++)pq[i].push(W + 1);
    for (int i = 1; i <= W; i++)pq[H + 1].push(i);
    int ans = 1e9;
    int cx = 1, cy = 1;
    while (true) {
        ans = min(ans, pq[cy].top() - 1);
        if (pq[cy].top() == cx + 1)break;
        cx++;
        while (pq[cy + 1].top() < cx)pq[cy + 1].pop();
        if (pq[cy + 1].top() != cx)cy++;
    }
    cout << ans << endl;

}