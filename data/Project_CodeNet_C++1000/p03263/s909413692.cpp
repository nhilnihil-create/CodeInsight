#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int MAX = 500;
int mat[MAX][MAX];
int h, w;

pair<int, int> next(int i, int j){
    int ni, nj;
    if(i % 2 == 0){
        if(j < w-1){
            ni = i, nj = j+1;
        } else {
            ni = i+1, nj = j;
        }
    } else {
        if(j > 0){
            ni = i, nj = j-1;
        } else {
            ni = i+1, nj = j;
        }
    }
    if(ni < 0 || h <= ni || nj < 0 || w <= nj){
        return make_pair(-1, -1);
    } else {
        return make_pair(ni, nj);
    }
}

int main(){
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }

    int i = 0, j = 0;
    vector<vector<int>> arr;
    while(1){
        int ni, nj;
        tie(ni, nj) = next(i, j);
        if(ni == -1 || j == -1) break;

        if(mat[i][j] % 2){
            mat[i][j]--;
            mat[ni][nj]++;
            arr.push_back({i, j, ni, nj});
        }

        i = ni, j = nj;
    }

    cout << arr.size() << endl;
    for(auto a : arr){
        for(int i = 0; i < 4; i++){
            if(i) cout << " ";
            cout << a[i]+1;
        }
        cout << endl;
    }

    return 0;
}