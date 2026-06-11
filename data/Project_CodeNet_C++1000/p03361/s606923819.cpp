#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                bool f = true;
                if (i != 0) if (s[i-1][j] == '#') f = false;
                if (i != h-1) if (s[i+1][j] == '#') f = false;
                if (j != 0) if (s[i][j-1] == '#') f = false;
                if (j != w-1) if (s[i][j+1] == '#') f = false;
                if (f) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
}