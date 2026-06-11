// 

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    // 入力
    int N, M; cin >> N >> M; // N:スイッチ総数, M:電球総数
    /* cout << "N, M 取得" << endl; */
    vector<vector<int>> S(M);
    vector<int> P(M);

    int test = 0;

    for (int m=0; m<M; ++m){
        /* cout << "\n" << "ループ" << test << "回目" << endl;  */
        int K; cin >> K;
        for(int k=0; k<K; k++){
            int s; cin >> s;
            S[m].push_back(s);
        }
        /*test += 1; */
    }

    for(int m=0; m<M; m++) cin >> P[m];
    
    // bit探索
    int ans =0;
    for (int ptn = 0; ptn<(1<<N); ptn++){
        vector<int> S_cnt(M); // 点灯スイッチ数格納用
        for (int j=0; j<N; j++){
            if (ptn>>j&1){
                for (int m=0; m<M; m++){
                    for (int k=0; k<S[m].size(); k++){
                        if(S[m][k] == j+1) S_cnt[m] += 1;
                    }
                }
            }
        }
        for (int m=0; m<M; m++){
            int tmp = S_cnt[m] % 2;
            if (tmp!=P[m]) break;
            if (m==M-1) ans += 1;   
        }
    }
    cout << ans << endl;
}