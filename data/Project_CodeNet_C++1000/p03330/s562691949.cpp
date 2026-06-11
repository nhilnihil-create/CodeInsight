#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n,c;
    cin >> n >> c;
    int d[30][30];
    int color[500][500];
    for(int x = 0; x < c; x++)
        for(int y = 0; y < c; y++)
            cin >> d[x][y];
    for(int x = 0; x < n; x++)
        for(int y = 0; y < n; y++)
            cin >> color[x][y];

    ll v[3][30] {};
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            for(int col = 0; col < c; col++){
                v[(x+y+2)%3][col] += d[color[x][y]-1][col];
            }
        }
    }

    ll ans = 1e+10;
    for(int x = 0; x < c; x++){
        for(int y = 0; y < c; y++){
            if(x == y) continue;
            for(int z = 0; z < c; z++){
                if(x == z || y == z) continue;
                ans = min(ans, v[0][x] + v[1][y] + v[2][z]);
            }
        }
    }
    cout << ans << endl;
}