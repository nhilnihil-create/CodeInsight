#include <bits/stdc++.h>
using namespace std;

int a[503][503];

signed main () {
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) 
            cin >> a[i][j];
    }
    vector < pair < pair < int, int >, pair < int, int > > > ans;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (a[i][j] & 1) {
                if (i < h && j < w) {
                    if (a[i + 1][j] & 1) {
                        ++a[i + 1][j];
                        ans.push_back(make_pair(make_pair(i, j), make_pair(i + 1, j)));
                    }
                    else {
                        ++a[i][j + 1];
                        ans.push_back(make_pair(make_pair(i, j), make_pair(i, j + 1)));
                    }
                }
                else if (j < w) {
                    ++a[i][j + 1];
                    ans.push_back(make_pair(make_pair(i, j), make_pair(i, j + 1)));
                }
                else if (i < h) {
                    ++a[i + 1][j];
                    ans.push_back(make_pair(make_pair(i, j), make_pair(i + 1, j)));
                }
            }
        }
    }
    cout << int(ans.size()) << '\n';
    for (auto uv: ans) {
        int xu = uv.first.first, yu = uv.first.second;
        int xv = uv.second.first, yv = uv.second.second;
        cout << xu << ' ' << yu << ' ' << xv << ' ' << yv << '\n';
    }
}
