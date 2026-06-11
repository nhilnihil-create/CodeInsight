#include <bits/stdc++.h>
using namespace std;  

int main() {
    int h, w;
    char s[52][52] = {};
    bool flg = true;
    
    cin >> h >> w;
    for ( int i = 0; i < h; i++ ) {
        for ( int j = 0; j < w; j++ ) {
            cin >> s[i+1][j+1];
        }
    }
    
    for ( int i = 1; i <= h; i++ ) {
        for ( int j = 1; j <= w; j++ ) {
            if ( s[i][j] == '#' ) {
                if ( s[i][j-1] == '.' && s[i][j+1] == '.' && s[i-1][j] == '.' && s[i+1][j] == '.' ) {
                    flg = 0;
                }
            }
        }
    }
    
    if ( flg ) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    
    return (0);
}
