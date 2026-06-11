#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, C;
    cin >> N >> C;
    vector<vector<long long>> D(C, vector<long long>(C)), c(N, vector<long long> (N));
    for(int i = 0; i < C; i++){
        for(int j = 0; j < C; j++) cin >> D[i][j];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    vector<vector<long long>> cnt(3, vector<long long> (C));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cnt[(i + j) % 3][c[i][j]]++;
        }
    }
    long long ans = 1e18;
    for(int i = 0; i < C; i++){
        for(int j = 0; j < C; j++){
            if(i == j) continue;
            for(int k = 0; k < C; k++){
                long long res = 0;
                if(i == k || j == k) continue;
                for(int l = 0; l < C; l++){
                    res += cnt[0][l] * D[l][i] + cnt[1][l] * D[l][j] + cnt[2][l] * D[l][k];
                }
                ans = min(ans, res);
            }
        }
    }
    cout << ans << endl;
}