#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    int cnt = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.') cnt++;
        }
    }

    queue<pii> q;
    pii g (h-1, w-1);
    q.push(pii(0,0));
    int stp = -1;
    for (int i = 1; 1; i++) {
        int j = q.size();
        for (int k = 0; k < j; k++) {
            if (q.front() == g) {
                stp = i;
                break;
            }
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            if (s[a][b] != '.') continue;
            s[a][b] = ':';
            if (a > 0)   q.push(pii(a-1, b));
            if (a < h-1) q.push(pii(a+1, b));
            if (b > 0)   q.push(pii(a, b-1));
            if (b < w-1) q.push(pii(a, b+1));
        }
        if (stp >= 0) break;
        if (q.empty()) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << cnt - stp << endl;
}