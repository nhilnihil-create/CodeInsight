# include <algorithm>
# include <cmath>
# include <iostream>
# include <map>
# include <queue>
# include <string>
# include <vector>

typedef long long ll;
using namespace std;

const ll mod = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) {
        string ss; cin >> ss;
        s[i] = ss;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int dx = i;
        bool valid = true;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                int newY = x - dx;
                int newX = y + dx;
                if (newX < 0) newX += n;
                else if (newX > n - 1) newX -= n;
                if (newY < 0) newY += n;
                else if (newY > n - 1) newY -= n;
                if (s[y][x] != s[newY][newX]) valid = false;
            }
        }
        if (valid) ans++;
    }
    cout << ans * n << endl;
    return 0;
}
