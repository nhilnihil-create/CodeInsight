#include <bits/stdc++.h>
using namespace std;

int main() {
    int h,w,d;
    cin >> h >> w >> d;

    int maxv = h * w;
    vector<pair<int,int>> a(maxv + 10);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int v;
            cin >> v;
            a[v].first = i;
            a[v].second = j;
        }
    }

    vector<vector<int>> dist(d + 1);
    for (int i = 1; i <= d; i++) {
        int cur = i;
        dist[cur % d].push_back(0);
        int sum = 0;
        while(true) {
            cur += d;
            if(cur > maxv) break;
            int curx = a[cur].first;
            int posx = a[cur - d].first;
            int cury = a[cur].second;
            int posy = a[cur - d].second;

            int len = abs(curx - posx) + abs(cury - posy);
            sum += len;
            dist[cur % d].push_back(sum);
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int s,g;
        cin >> s >> g;

        int m = g % d;
        int sitr = (s - m) / d;
        int gitr = (g - m) / d;
        if(m == 0) sitr--, gitr--;
        cout << dist[m][gitr] - dist[m][sitr] << endl;
    }

}