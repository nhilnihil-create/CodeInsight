#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> x(N), y(N), h(N);
    for(int i = 0; i < N; i++) cin >> x[i] >> y[i] >> h[i];
    vector<vector<int>> d(101, vector<int> (101, -1));
    int flag = 0;
    for(int i = 0; i < N; i++){
        if(h[i] > 0) flag = 1;
    }
    int flag2 = 0;
    for(int i = 0; i < N; i++){
        int a = 0;
        for(int j = -100; j <= 100; j++){
            for(int k = -100; k <= 100; k++){
                int nx = x[i] + j, ny = y[i] + k;
                int nd = h[i] + abs(j) + abs(k);
                if(flag == 1 && 0 <= nx && nx <= 100 && 0 <= ny && ny <= 100){
                    if(flag2 == 0 && h[i] != 0){
                        d[nx][ny] = nd;
                        a = 1;
                    }
                    else if(h[i] != 0){
                        if(d[nx][ny] != nd) d[nx][ny] = -1;
                    }
                }
                else if(flag == 0 && 0 <= nx && nx <= 100 && 0 <= ny && ny <= 100){
                    if(flag2 == 0){
                        d[nx][ny] = nd;
                        a = 1;
                    }
                    else{
                        if(d[nx][ny] != nd) d[nx][ny] = -1;
                    }
                }
                
            }
        }
        if(a == 1) flag2 = 1; 
    }
    if(flag == 1){
        for(int i = 0; i < 101; i++){
            for(int j = 0; j < 101; j++){
                for(int k = 0; k < N; k++){
                    if(h[k] == 0 && d[i][j] - abs(x[k] - i) - abs(y[k] - j) > 0) d[i][j] = -1;
                }
            }
        }
    }
    int ans = -1;
    int cx, cy;
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            if(ans < d[i][j]){
                ans = d[i][j];
                cx = i;
                cy = j;
            }
        }
    }
    printf("%d %d %d\n", cx, cy, ans);
}