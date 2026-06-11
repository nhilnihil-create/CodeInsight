#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    long long N, C;
    cin >> N >> C;
    vector<vector<int>> D(C, vector<int> (C)), c(N, vector<int> (N));
    for(int i = 0; i < C; i++){
        for(int j = 0; j < C; j++) cin >> D[i][j];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> c[i][j];
    }
    map<long long, long long> m0, m1, m2;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if((i + j) % 3 == 0) m0[c[i][j] - 1]++;
            if((i + j) % 3 == 1) m1[c[i][j] - 1]++;
            if((i + j) % 3 == 2) m2[c[i][j] - 1]++;
        }
    }
    long long ans = 1e18;
    for(int i = 0; i < C; i++){
        for(int j = 0; j < C; j++){
            if(i != j){
                for(int k = 0; k < C; k++){
                    if(j != k && i != k){
                        long long res = 0;
                        for(auto u: m0){
                            res += u.second * D[u.first][i];
                        }
                        for(auto u: m1){
                            res += u.second * D[u.first][j];
                        }
                        for(auto u: m2){
                            res += u.second * D[u.first][k];
                        }
                        ans = min(ans, res);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}