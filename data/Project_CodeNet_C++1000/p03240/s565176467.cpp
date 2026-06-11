#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> x(N), y(N), h(N);
    for(int i = 0; i < N; i++) cin >> x[i] >> y[i] >> h[i];
    int flag = 0;
    for(int i = 0; i < N; i++){
        if(h[i] > 0) flag = 1;
    }
    if(flag == 0){
        for(int i = 0; i <= 100; i++){
            for(int j = 0; j <= 100; j++){
                int flag = 0;
                for(int k = 0; k < N; k++){
                    if(i == h[k] && j == h[k]) flag = 1;
                }
                if(flag == 0){
                    cout << i << ' ' << j << ' ' << 1 << endl;
                    return 0;
                }
            }
        }
    }
    vector<vector<int>> d(101, vector<int> (101, -1));
    for(int i = 0; i < N; i++){
        if(h[i] > 0){
            for(int j = -100; j <= 100; j++){
                for(int k = -100; k <= 100; k++){
                    int nx = x[i] + j, ny = y[i] + k;
                    if(0 <= nx && nx <= 100 && 0 <= ny && ny <= 100){
                        d[nx][ny] = h[i] + abs(j) + abs(k);
                    }
                }
            }
            break;
        }
    }
    int ans = 0, cx, cy;
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            int flag = 0;
            for(int k = 0; k < N; k++){
                if(h[k] != 0 && d[i][j] - abs(x[k] - i) - abs(y[k] - j) != h[k]) flag = 1;
                else if(h[k] == 0 && d[i][j] - abs(x[k] - i) - abs(y[k] - j) > h[k]) flag = 1;
            }
            if(flag == 0 && ans < d[i][j]){
                ans = d[i][j];
                cx = i;
                cy = j;
            }
        }
    }
    cout << cx << ' ' << cy << ' ' << ans << endl;
}