#include <bits/stdc++.h>

using namespace std;

long long dx[] = {-1, 1, 0, 0};
long long dy[] = {0, 0, -1, 1};
char dir[] = {'L', 'R', 'D', 'U'};

int get(int x, int y) {
    return (((x + y) % 2) + 2) % 2;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if (i > 0 && get(x[i - 1], y[i - 1]) != get(x[i], y[i])) {
            cout << -1; return;
        }
    }
    int parity = get(x[0], y[0]);
    cout << 31 + (parity == 0) << "\n";
    for (int i = 0; i <= 30; i++) {
        cout << (1 << i) << ' ';
    }
    if (!parity) cout << 1 << ' ';
    cout << "\n";
    for (int i = 0; i < n; i++) {
        string s;
        if (!parity) s.push_back('D'), y[i]++;
        for (int j = 30; j >= 0; j--) {
            for (int k = 0; k < 4; k++) {
                long long nx = x[i] + 1LL * dx[k] * (1 << j), ny = y[i] + 1LL * dy[k] * (1 << j);
                if (abs(nx) + abs(ny) <= (1 << j) - 1) {
                    x[i] = nx, y[i] = ny;
                    s.push_back(dir[k ^ 1]);
                    break;
                }
            }
        }
        reverse(s.begin(), s.end());
        cout << s << "\n";
    }
}

int main() {
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    solve();
}
