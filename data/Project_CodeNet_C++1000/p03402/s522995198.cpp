#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    vector<vector<char>> upper(50, vector<char>(100, '.'));
    vector<vector<char>> lower(50, vector<char>(100, '#'));
    int sx = 0, sy = 0;
    for(int i=0; i<b-1; i++){
        upper[sx][sy] = '#';
        sy += 2;
        if(sy == 100){
            sx += 2;
            sy = 0;
        }
    }
    sx = 49; sy = 0;
    for(int i=0; i<a-1; i++){
        lower[sx][sy] = '.';
        sy += 2;
        if(sy == 100){
            sx -= 2;
            sy = 0;
        }
    }

    cout << 100 << " " << 100 << endl;
    for(int i=0; i<50; i++){
        for(int j=0; j<100; j++){
            cout << upper[i][j];
        }cout << endl;
    }
    for(int i=0; i<50; i++){
        for(int j=0; j<100; j++){
            cout << lower[i][j];
        }cout << endl;
    }
    return 0;
}