#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> LR(N, vector<int>(N, 0));
    int Li, Ri, pi, qi;
    for(int i=0;i<M;i++){
        cin >> Li >> Ri;
        LR[Li-1][Ri-1]++;
    }
    vector<vector<int>> LR2(N, vector<int>(N, 0));
    for(int i=0;i<N;i++){
        LR2[i][i] += LR[i][i];
        for(int j=i+1;j<N;j++){
            LR2[i][j] += LR2[i][j-1] + LR[i][j];
        }
    }
    for(int i=N-2;i>=0;i--){
        for(int j=i+1;j<N;j++){
            LR2[i][j] += LR2[i+1][j];
        }
    }

    vector<int> res(Q, 0);
    for(int i=0;i<Q;i++){
        cin >> pi >> qi;
        res[i] = LR2[pi-1][qi-1];
    }
    for(auto v : res) cout << v << endl;

    return 0;
}