#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> d(N + 1, vector<int> (N + 1, 0));
    for(int i = 0; i < M; i++){
        int l, r;
        cin >> l >> r;
        d[l][r]++;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            d[i + 1][j + 1] = d[i + 1][j] + d[i + 1][j + 1];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            d[j + 1][i + 1] = d[j][i + 1] + d[j + 1][i + 1];
        }
    }
    for(int i = 0; i < Q; i++){
        int p, q;
        cin >> p >> q;
        cout << d[q][q] - d[p - 1][q] - d[q][p - 1] + d[p - 1][p - 1] << endl;
    }
}