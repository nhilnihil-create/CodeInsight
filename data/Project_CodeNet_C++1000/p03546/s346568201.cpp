#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

const int INF = 1e9;
const int MAX = 2500;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int> > cost(10, vector<int>(10));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> cost[i][j];
        }
    }

    vector<vector<int> > list(h, vector<int>(w));    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> list[i][j];
        }
    }
    
    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    ll tmp = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (list[i][j] < 0) {
                continue;
            }
            tmp += cost[list[i][j]][1];
        }
    }
    cout << tmp << endl;
    return 0;
}