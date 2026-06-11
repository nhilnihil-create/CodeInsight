#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    int N,C;
    cin >> N >> C;
    int D[C][C];
    map<int,int> m0, m1, m2;
    for(int i = 0; i < C; i++){
        m0[i] = 0;
        m1[i] = 0;
        m2[i] = 0;
    }

    for(int i = 0; i < C; i++){
        for(int j = 0; j < C; j++){
            int tmp;
            cin >> tmp;
            D[i][j] = tmp;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int tmp;
            cin >> tmp;
            tmp--;
            if((i+j) % 3 == 0){
                m0[tmp]++;
            }
            if((i+j) % 3 == 1){
                m1[tmp]++;
            }
            if((i+j) % 3 == 2){
                m2[tmp]++;
            }
        }
    }

    int ans = 30*30*500*1000;
    for(int i = 0; i < C; i++){
        for(int j = 0; j < C; j++){
            if(i == j) continue;
            for(int k = 0; k < C; k++){
                int tmp = 0;
                if(j == k || i == k) continue;
                for(auto x: m0){
                    tmp += D[x.first][i] * x.second;
                }
                for(auto x: m1){
                    tmp += D[x.first][j] * x.second;
                }
                for(auto x: m2){
                    tmp += D[x.first][k] * x.second;
                }
                if(tmp < ans){
                    ans = tmp;
                }
            }
        }
    }
    cout << ans << endl;
}
