#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;


int main() {
    int h,w; cin >> h >> w;
    char s[51][51];
    int f = true;
    int fb = false;

    rep(i,h){
        rep(j,w){
            cin >> s[i][j];
        }
    }

    rep(i,h){
        rep(j,w){
            fb = false;
            if(s[i][j] == '#') {
                if (i != 0 && s[i - 1][j] == '#') fb = true;
                if (i != h - 1 && s[i + 1][j] == '#') fb = true;
                if (j != 0 && s[i][j - 1] == '#') fb = true;
                if (j != w - 1 && s[i][j + 1] == '#') fb = true;

                if (!fb) {
                    f = false;
                    break;
                }
            }
        }
    }

    cout << ((f)?"Yes":"No");
    return 0;
}









