#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, Q; cin >> N >> M >> Q;
    vector<int> l(M), r(M);
    vector<vector<int>> num(N+1, vector<int>(N+1));
    for(int i = 0; i < M; i++){
        cin >> l[i] >> r[i];
        num[l[i]][r[i]]++;
    }
    vector<vector<int>> ans(N+1, vector<int>(N+1));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            ans[i][j] = ans[i][j-1] + num[i][j];
        }
    }
    while(Q--){
        int p, q; cin >> p >> q;
        int FA = 0;
        for(int i = p; i <= q; i++){
            FA += ans[i][q];
        }
        cout << FA << endl;
    }
}