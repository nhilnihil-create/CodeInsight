#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

int main() {
    int N;
    cin>>N;
    vector<vector<int>> G(N);
    int cnt = 0;
    REP(i, 1, N+1) REP(j, i, N+1){
        if(i == j) continue;
        if(i+j != N + (N+1)%2){
            G[i-1].emplace_back(j);
            cnt++;
        }
    }
    cout << cnt << endl;
    REP(i, 0, N) {
        REP(j, 0, G[i].size()){
            cout << i+1 << " " << G[i][j] << endl;
        }
    }
}