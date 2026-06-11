#include <iostream>
#include <string>
#include <array>

using namespace std;

int main() {
    int n, i, x, y;
    cin >> n;

    array<string, 500> s;
    for(i = 0; i < n; i++) cin >> s[i];

    int ans = 0, xx, yy;
    for(i = 0; i < n; i++) {
        for(x = 0; x < n; x++) {
            for(y = 0; y < n; y++) {
                xx = y - i < 0 ? n + y - i : y - i;
                yy = x + i >= n ? x + i - n : x + i;
                if(s[x][y] != s[xx][yy]) goto XX;
            }
        }
    ans += 1;
  XX:
    continue;
    }

    cout << ans * n << endl;
}