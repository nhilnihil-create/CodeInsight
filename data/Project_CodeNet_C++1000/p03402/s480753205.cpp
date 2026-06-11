#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 998244353;
//printf("%.10f\n", n);
char maze[101][101];
signed main() {
    ll n, m, a = 1, b = 1; cin >> n >> m;
    cout << 100 << ' ' << 100 << endl;
    if (n < m) {
        while (true) {
            if (n == 1) { break; }
            maze[a][b] = '.'; maze[a + 1][b + 1] = '#';
            maze[a + 1][b] = '#'; maze[a][b + 1] = '#';
            b += 2;
            if (b > 100) { b = 1; a += 2; }
            n--;
        }
        for (int h = 1; h <= 20; h++) {
            for (int i = 1; i <= 100; i++) {
                if (maze[h][i] != '.') { maze[h][i] = '#'; }
            }
        }
        for (int i = 1; i <= 100; i++) { maze[21][i] = '.'; }
        a = 22; b = 1; m--;
        while (true) {
            if (m == 0) { break; }
            maze[a][b] = '#'; maze[a + 1][b + 1] = '.';
            maze[a + 1][b] = '.'; maze[a][b + 1] = '.';
            b += 2;
            if (b > 100) { b = 1; a += 2; }
            m--;
        }
        for (int h = 1; h <= 100; h++) {
            for (int i = 1; i <= 100; i++) {
                if (maze[h][i] != '#') { maze[h][i] = '.'; }
            }
        }
        for (int h = 1; h <= 100; h++) {
            for (int i = 1; i <= 100; i++) {
                cout << maze[h][i];
            }
            cout << endl;
        }
    }
    else {
        swap(n, m);
        while (true) {
            if (n == 1) { break; }
            maze[a][b] = '#'; maze[a + 1][b + 1] = '.';
            maze[a + 1][b] = '.'; maze[a][b + 1] = '.';
            b += 2;
            if (b > 100) { b = 1; a += 2; }
            n--;
        }
        for (int h = 1; h <= 20; h++) {
            for (int i = 1; i <= 100; i++) {
                if (maze[h][i] != '#') { maze[h][i] = '.'; }
            }
        }
        for (int i = 1; i <= 100; i++) { maze[21][i] = '#'; }
        a = 22; b = 1; m--;
        while (true) {
            if (m == 0) { break; }
            maze[a][b] = '.'; maze[a + 1][b + 1] = '#';
            maze[a + 1][b] = '#'; maze[a][b + 1] = '#';
            b += 2;
            if (b > 100) { b = 1; a += 2; }
            m--;
        }
        for (int h = 1; h <= 100; h++) {
            for (int i = 1; i <= 100; i++) {
                if (maze[h][i] != '.') { maze[h][i] = '#'; }
            }
        }
        for (int h = 1; h <= 100; h++) {
            for (int i = 1; i <= 100; i++) {
                cout << maze[h][i];
            }
            cout << endl;
        }
    }
    return 0;
}