#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll INF = 0x3f3f3f3f;
const ll LINF = 1ll << 55;
const ll MOD = 1e9 + 7;
const ll MAXN = 400 + 5;
const ll MAXK = 1e5 + 10;

const ll dx[] = {1, 0, -1, 0};
const ll dy[] = {0, 1, 0, -1};

int main() {
    ll A, B;
    cin >> A >> B;
    vector<vector<char>> grid(100, vector<char>(100, '#'));
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 100; ++j) {
            grid[i][j] = '.';
        }
    }
    bool ok = true;
    bool update = false;
    for (int i = 0; i < B - 1; ++i) {
        update = false;
        for (int j = 0; j < 50 - 1; ++j) {
            for (int k = 0; k < 100; ++k) {
                ok = true;
                for (int x = -1; x <= 1; ++x) {
                    for (int y = -1; y <= 1; ++y) {
                        int dj = j + x;
                        int dk = k + y;
                        if (dj >= 0 && dj < 50 - 1 && dk >= 0 && dk < 100 && grid[dj][dk] != '.') {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) {
                        break;
                    }
                }
                if (ok) {
                    grid[j][k] = '#';
                    update = true;
                    break;
                }
            }
            if (update) {
                break;
            }
        }
    }

    for (int i = 0; i < A - 1; ++i) {
        update = false;
        for (int j = 51; j < 100; ++j) {
            for (int k = 0; k < 100; ++k) {
                ok = true;
                for (int x = -1; x <= 1; ++x) {
                    for (int y = -1; y <= 1; ++y) {
                        int dj = j + x;
                        int dk = k + y;
                        if (dj >= 51 && dj < 100 && dk >= 0 && dk < 100 && grid[dj][dk] != '#') {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) {
                        break;
                    }
                }
                if (ok) {
                    grid[j][k] = '.';
                    update = true;
                    break;
                }
            }
            if (update) {
                break;
            }
        }
    }
    cout << 100 << " " << 100 << endl;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}