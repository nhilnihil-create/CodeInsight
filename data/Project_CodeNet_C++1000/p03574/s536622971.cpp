#include <iostream>
using namespace std;
int main() {
    int h, w;
    cin >> h >> w;
    char c[h][w];
    int cnt[h+2][w+2] = {};
    string s;
    for (int i=0; i<h; i++) {
        cin >> s;
        for (int j=0; j<w; j++) {
            c[i][j] = s[j];
            if (c[i][j] == '#') {
                cnt[i][j]++;
                cnt[i][j+1]++;
                cnt[i][j+2]++;
                cnt[i+1][j]++;
                cnt[i+1][j+2]++;
                cnt[i+2][j]++;
                cnt[i+2][j+1]++;
                cnt[i+2][j+2]++;
            }
        }
    }
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (c[i][j] == '.') {
                cout << cnt[i+1][j+1];
            } else {
                cout << '#';
            }
        }
        cout << endl;
    }
}