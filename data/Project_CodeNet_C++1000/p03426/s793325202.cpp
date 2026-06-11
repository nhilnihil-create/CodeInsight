#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 1000000;


int main() {
    int H, W, D, Q;
    cin >> H >> W >> D;
    int A[H][W];
    map<int, pair<int, int>>mp;
    vector<vector<ll>>v(D+1);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            mp[A[i][j]] = make_pair(i+1, j+1);
        }
    }
    for (int i = 1; i <= D; i++) {
        ll sum = 0;
        v[i].push_back(0);
        for (int j = i; j+D <= H*W; j += D) {
            sum += abs(mp[j].first-mp[j+D].first) + abs(mp[j].second-mp[j+D].second);
            v[i].push_back(sum);
        }
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R;
        ll total = 0;
        cin >> L >> R;
        if (L==R) {
            cout << 0 << endl;
            continue;
        }
        if (L % D == 0) {
            total = v[D][(R-D)/D] - v[D][(L-D)/D];
        } else {
            total = v[L%D][(R-(L%D))/D] - v[L%D][(L-(L%D))/D];
        }
        cout << total << endl;
    }
}
