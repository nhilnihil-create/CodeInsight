#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const vector<vector<int>> dir4 = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const vector<vector<int>> dir8 = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

int main()
{
    int h = 100, w = 100;
    int a, b; cin >> a >> b;
    a--, b--;
    vector<vector<int>> grd(h, vector<int>(w));
    for(int i = 0; i < h / 2; i++) {
        for(int j = 0; j < w; j++)grd[i][j] = 1;
    }
    
    for(int i = 1; i < h / 2 - 1; i++) {
        for(int j = 1; j < w - 1 && b; j++) {
            bool res = 1;
            for(auto d : dir8)if(grd[i + d[0]][j + d[1]] == 0)res = false;
            if(res)grd[i][j] = 0;
            if(res)b--;
        }
    }

    cerr << "27" << endl;

    for(int i = h / 2 + 2; i < h - 1; i++) {
        for(int j = 1; j < w - 1 && a; j++) {
            bool res = 1;
            for(auto d : dir8)if(grd[i + d[0]][j + d[1]] == 1)res = false;
            if(res)grd[i][j] = 1;
            if(res)a--;
        }
    }

    cerr << "35" << endl;

    cout << h << " " << w << endl;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << (grd[i][j] ? '.' : '#');
        }
        cout << endl;
    }

}