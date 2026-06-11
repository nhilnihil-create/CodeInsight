#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const int MAX = 50;
const int INF = 1e+5;
int mat[MAX][MAX];
int h, w;

void check(int i, int j){
    if(i < 0 || h <= i) return;
    if(j < 0 || w <= j) return;
    mat[i][j]++;
}

int main(){
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char ch;
            cin >> ch;
            if(ch == '#'){
                check(i+1, j);
                check(i, j+1);
                check(i-1, j);
                check(i, j-1);
                check(i+1, j+1);
                check(i+1, j-1);
                check(i-1, j+1);
                check(i-1, j-1);
                mat[i][j] = INF + 8;
            }
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mat[i][j] >= INF){
                cout << '#';
            } else {
                cout << (char)(mat[i][j] + '0');
            }
        }
        cout << endl;
    }
    return 0;
}