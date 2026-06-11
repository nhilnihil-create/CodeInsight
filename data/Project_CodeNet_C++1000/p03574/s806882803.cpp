#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    
    char s[h][w];
    int ans[h][w];
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> s[i][j];
            ans[i][j] = 0;
        }
    }
        
    
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (s[i][j] == '#') {
                if (i >= 1) {
                // if (ans[i-1][j] == -1) {
                //     continue;
                // }
                ans[i-1][j]++;
                    if (j > 0) {
                // if (ans[i-1][j-1] == -1) {
                //     continue;
                // }
                        ans[i-1][j-1]++;
                    }
                    if (j < w-1) {
                // if (ans[i-1][j+1] == -1) {
                //     continue;
                // }
                        ans[i-1][j+1]++;
                    }
                }
                if (j > 0) {
                // if (ans[i][j-1] == -1) {
                //     continue;
                // }
                    ans[i][j-1]++;
                }
                if (j < w-1) {
                // if (ans[i][j+1] == -1) {
                //     continue;
                // }
                    ans[i][j+1]++;
                }
                if (i < h-1) {
                // if (ans[i+1][j] == -1) {
                //     continue;
                // }
                    ans[i+1][j]++;
                    if (j > 0) {
                // if (ans[i+1][j-1] == -1) {
                //     continue;
                // }
                        ans[i+1][j-1]++;
                    }
                    if (j < w-1) {
                // if (ans[i+1][j+1] == -1) {
                //     continue;
                // }
                        ans[i+1][j+1]++;
                    }
                }
            }
        }
    }
    
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (s[i][j] == '#') {
                cout << '#';
            } else {
            cout << ans[i][j];
            }
        }
        cout << endl;
    }

}
