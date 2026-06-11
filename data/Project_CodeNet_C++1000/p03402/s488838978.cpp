#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 100;

int main(){
    int A, B; cin >> A >> B;
    cout << MAX_N << " " << MAX_N << endl;

    vector<vector<char> > ans(MAX_N, vector<char>(MAX_N));
    rep(i, 0, 100){
        rep(j, 0, 100){
            if(i < 50) ans[i][j] = '.';
            else ans[i][j] = '#';
        }
    }

    int cnt = 1;
    int idx_i = 0, idx_j = 0;
    while(cnt < B){
        ans[idx_i][idx_j] = '#';
        cnt++;
        if(idx_j == 98){
            idx_j = 0;
            idx_i += 2;
        }else{
            idx_j += 2;
        }
    }
    cnt = 1;
    idx_i = 99, idx_j = 0;
    while(cnt < A){
        ans[idx_i][idx_j] = '.';
        cnt++;
        if(idx_j == 98){
            idx_j = 0;
            idx_i -= 2;
        }else{
            idx_j += 2;
        }
    }
    rep(i, 0, MAX_N){
        rep(j, 0, MAX_N){
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}