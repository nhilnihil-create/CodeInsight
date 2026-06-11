#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M, ans = 0;
    cin >> N >> M;
    vector<int> k(M+1);
    vector<int> p(M+1);
    vector<vector<int>> s(M+1, vector<int>());
    for(int i = 1; i <= M; ++i){
        cin >> k[i];
        s[i].resize(k[i]+1);
        for(int j = 1; j <= k[i]; ++j) cin >> s[i][j];
    }
    for(int i = 1; i <= M; ++i) cin >> p[i];
    for(int i = 0; i < pow(2,N); ++i){
        vector<int> buf(M+1, false);
        vector<bool> tmp(N+1, false);
        int flag = 1;
        for(int j = 0; j < N; ++j){
            if((i >> j) & 1) tmp[j+1] = true;
        }
        for(int j = 1; j <= M; ++j){
            for(int l = 1; l <= k[j]; ++l){
                if(tmp[s[j][l]]) ++buf[j];
            }
            if(buf[j] % 2 != p[j]){
                flag = 0;
                break;
            }
        }
        if(flag) ++ans;
    }
    cout << ans << endl;
    return 0;
}