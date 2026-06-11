#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const vector<vector<int>> dir4 = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const vector<vector<int>> dir8 = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

int main()
{
    int h, w; cin >> h >> w;
    vector<vector<bool>> a(h + 2, vector<bool>(w + 2));
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            char c; cin >> c;
            a[i][j] = (c == '#');
        }
    }

    bool res = true;
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            bool f = false;
            if(a[i][j]) {
                for(auto d: dir4)if(a[i + d[0]][j + d[1]])f = true;
                if(!f)res = false;

            }
        }
    }
    cout << (res ? "Yes" : "No") << endl;
}