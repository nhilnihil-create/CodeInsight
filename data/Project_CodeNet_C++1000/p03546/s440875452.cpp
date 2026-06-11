#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
    int H, W; cin >> H >> W;
    vector<vector<int>> cost(10,vector<int>(10));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> cost[i][j];
        }
    }

    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int num; cin >> num;
            if (num == -1) continue;
            ans += cost[num][1];
        }
    }
    cout << ans << endl;
}