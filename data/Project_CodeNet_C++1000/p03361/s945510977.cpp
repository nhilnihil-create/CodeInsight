#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w; cin >>h >>w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >>s[i];

    string ret = "Yes";
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                if (i>0   && s[i-1][j]=='#') continue;
                if (i<h-1 && s[i+1][j]=='#') continue;
                if (j>0   && s[i][j-1]=='#') continue;
                if (j<w-1 && s[i][j+1]=='#') continue;

                ret = "No"; // 四方を探してだめならNoとなる
                break;
            }
        }
        if (ret == "No") break;
    }
    cout << ret << endl;
    return 0;
}