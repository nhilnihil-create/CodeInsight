#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
const ll INF = 1e9;

int main() {
    int a,b; cin >> a >> b;

    vector<vector<char>> grid1(50,vector<char>(100,'#'));
    vector<vector<char>> grid2(50,vector<char>(100,'.'));
    
    int i1 = 1;
    int j1 = 1;
    while (a > 1) {
        grid1[i1][j1] = '.';
        a -= 1;
        j1 += 2;
        if (j1 == 101) {
            i1 += 2;
            j1 = 1;
        }
    }

    int i2 = 1;
    int j2 = 1;
    while (b > 1) {
        grid2[i2][j2] = '#';
        b -= 1;
        j2 += 2;
        if (j2 == 101) {
            i2 += 2;
            j2 = 1;
        }
    }
    
    cout << 100 << ' ' << 100 << endl;
    for (int i = 0; i < 50; i ++) {
        for (int j = 0; j < 100; j ++ ) {
            cout << grid1[i][j];
        }
        cout << '\n';
    }
    for (int i = 0; i < 50; i ++) {
        for (int j = 0; j < 100; j ++ ) {
            cout << grid2[i][j];
        }
        cout << '\n';
    }

}