#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const vector<vector<int>> dir4 = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const vector<vector<int>> dir8 = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

int main()
{
    int h, w; cin >> h >> w;
    vector<string> gr(h + 2, string(w + 2, '.'));
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            char c; cin >> c; gr[i][j] = c;
        }
    }

    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            if(gr[i][j] != '#')continue;
            bool r = false;
            for(auto d: dir4) if(gr[i + d[0]][j + d[1]] == '#')r = true;
            if(!r) {cout << "No" << endl; return 0;}
        }
    }
    cout << "Yes" << endl;
}