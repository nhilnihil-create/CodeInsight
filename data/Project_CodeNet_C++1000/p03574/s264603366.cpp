#include <iostream>
#include <algorithm>

using namespace std;

int add(char c) {
    return ((c == '#') ? 1 : 0);
}

void solve() {
    int h, w;
    cin >> h >> w;
    char s[h+2][w+2];
    for (int i=0;i<h+2;i++) {
        for (int j=0;j<w+2;++j) {
            s[i][j] = 0;
        }
    }
    for (int i=1;i<=h;i++) {
        for (int j=1;j<=w;++j) {
            cin >> s[i][j];
        }
    }
    for (int i=1;i<=h;i++) {
        for (int j=1;j<=w;++j) {
            if (s[i][j] == '.') {
                s[i][j] = add(s[i][j-1]) + add(s[i][j+1]);
                s[i][j] += add(s[i-1][j-1]) + add(s[i-1][j]) + add(s[i-1][j+1]);
                s[i][j] += add(s[i+1][j-1]) + add(s[i+1][j]) + add(s[i+1][j+1]);
                s[i][j] += '0';
            };
        }
    }
    for (int i=1;i<=h;i++) {
        for (int j=1;j<=w;++j) {
            cout << s[i][j];
        }
        putchar('\n');
    }
}

int main() {
	solve();
    return 0;
}
