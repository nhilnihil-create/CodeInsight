#include <bits/stdc++.h>
using namespace std;
int main(){
    long long N, M;
    cin >> N >> M;
    vector<vector<long long>> r(N, vector<long long> (3));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++) cin >> r[i][j];
    }
    vector<vector<long long>> a(8, vector<long long> (N));
    vector<long long> ans(8, 0);
    for(int bit = 0; bit < (1 << 3); bit++){
        for(int j = 0; j < 3; j++){
            for(int i = 0; i < N; i++){
                if(bit & (1 << j)) a[bit][i] += r[i][j];
                else a[bit][i] -= r[i][j];
            }
        }
    }
    for(int i = 0; i < 8; i++) sort(a[i].begin(), a[i].end());
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < M; j++) ans[i] += a[i][N - 1 - j];
    }
    long long res = 0;
    for(int i = 0; i < 8; i++) res = max(res, ans[i]);
    cout << res << endl;
}