#include "bits/stdc++.h"
using namespace std;
#define int long long
#define ll long long

int dist(int x, int y, int x2, int y2) {
    return abs(x-x2) + abs(y-y2);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        if((abs(x[i]) + abs(y[i]))%2 != (abs(x[0]) + abs(y[0]))%2) {
            cout << "-1\n";
            return 0;
        }
    }
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    string dirs = "LRDU";
    vector<int> dists;
    for(int i = 31; i >= 0; --i) {
        dists.push_back(1LL<<i);
    }
    dists.push_back(1);
    if((abs(x[0]) + abs(y[0]))%2 == 1) dists.pop_back();
    cout << dists.size() << '\n';
    for(int dist : dists) cout << dist << ' ';cout << '\n';
    for(int i = 0; i < n; ++i) {
        int currX = x[i], currY = y[i];
        string s = "";
        int power = 31;
        for(int currDist : dists) {
            int best = 1e12;
            char dir;
            int pos;
            for(int k = 0; k < 4; ++k) {
                const int nextX = currX + dx[k]*currDist;
                const int nextY = currY + dy[k]*currDist;
                if(abs(nextX)+abs(nextY) <= (1LL<<power)) {
                    currX = nextX;
                    currY = nextY;
                    dir = dirs[k];
                    break;
                }
            }
            power = max(0LL, power-1);
            s += dir;
        }
        //cout << "currs (should be origin): " << currX << ' ' << currY << '\t';
        cout << s << '\n';
    }
    
    return 0;
}














