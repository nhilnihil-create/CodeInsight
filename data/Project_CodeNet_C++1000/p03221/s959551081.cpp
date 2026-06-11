#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N,M;
    cin >> N >> M;
    vector<int64_t> P(M),Y(M);
    for ( int64_t i = 0; i < M; ++i){
        cin >> P[i] >> Y[i];
    }
    
    
    vector<vector<int64_t>> X(M,vector<int64_t>(2)); // year, number
    for ( int64_t i = 0; i < M; ++i){
        X[i][0] = Y[i];
        X[i][1] = i;
    }
    sort(X.begin(),X.end());
    
    //vector<vector<int64_t>> Z(M,vector<int64_t>(2)); // number, fast
    map<int64_t,int64_t> m,m2;
    for ( int64_t i = 0; i < M; ++i){
        int64_t x = X[i][1];
        int64_t p = P[X[i][1]];
        m[p] = m[p] + 1;
        // 市pができたのはm[p]番目
        m2[x] = m[p];
    }
    
    for ( int64_t i = 0; i < M; ++i){
        int64_t a = P[i]; // 何市にあるか
        int64_t b = m2[i]; // 何番目にできたか
        int64_t ak = unsigned (log10(a) + 1);
        int64_t bk =unsigned (log10(b) + 1);
        for ( int64_t i = 0; i < 6-ak; ++i){
            cout << "0";
        }
        cout << a;
        for ( int64_t i = 0; i < 6-bk; ++i){
            cout << "0";
        }
        cout << b << endl;
    }
    
    
    return 0;
}
