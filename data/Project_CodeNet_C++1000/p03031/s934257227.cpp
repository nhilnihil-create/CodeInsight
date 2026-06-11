#include <bits/stdc++.h>
using namespace std;
#include <vector>

int main(){
    // input
    int N, M; cin >> N >> M;
    vector<vector<int>> S(M);
    vector<int> P(M);
    for (int m=0; m<M; m++){
        int K; cin >> K;
        for (int k=0; k<K; k++){
            int s; cin >>s;
            S[m].push_back(s);
        }
    }
    for ( int m=0; m<M; m++) cin >> P[m];

    // bit全探索
    int ans = 0;
    for (int ptn=0; ptn<(1<<N); ptn++){
        for(int m=0; m<M; m++){
            int cnt = 0;
            for(int k=0; k<S[m].size(); k++){
                if( (ptn>>(S[m][k]-1))&1 ) cnt++; // S[m][k]-1 桁目にフラグ存在すればcnt++
            }

            if( P[m] != (cnt%2) ) break;
            if( m == M-1 ) ans ++;
        }
    }
    cout << ans << endl;
}