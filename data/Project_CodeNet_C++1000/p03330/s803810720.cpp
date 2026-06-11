#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N, C; cin >> N >> C;
    vector<vector<int>> D(C, vector<int>(C));
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            cin >> D[i][j];
        }
    }
    vector<vector<int>> c(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    map<int, int> zero;
    map<int, int> one;
    map<int, int> two;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i + j) % 3 == 0) zero[c[i][j]]++;
            if ((i + j) % 3 == 1) one[c[i][j]]++;
            if ((i + j) % 3 == 2) two[c[i][j]]++;
        }
    }
    ll ans = 1e12;
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = 0; k < C; k++) {
                if (i == j || j == k || k == i) continue;
                ll tans = 0;
                for (auto x : zero) tans += D[x.first][i] * x.second;
                for (auto x : one) tans += D[x.first][j] * x.second;
                for (auto x : two) tans += D[x.first][k] * x.second;
                ans = min(tans, ans);
            }
        }
    }
    cout << ans << endl;
}
