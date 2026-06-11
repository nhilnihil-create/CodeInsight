#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<bool>> grid(100, vector<bool>(100, true));
    for (int i = 50; i < 100; i++){
        for (int j = 0; j < 100; j++) grid[i][j] = false;
    }
    int a, b;
    cin >> a >> b;
    a--; b--;
    for (int i = 0; i < b; i++){
        grid[2 * i / 100 * 2][(2 * i) % 100] = false;
    }
    for (int i = 0; i < a; i++){
        grid[99 - 2 * i / 100 * 2][(2 * i) % 100] = true;
    }
    cout << "100 100" << endl;
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if (grid[i][j]) cout << ".";
            else cout << "#";
        }
        cout << endl;
    }
}