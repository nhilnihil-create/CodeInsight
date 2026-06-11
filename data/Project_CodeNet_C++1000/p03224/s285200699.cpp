#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int main(){

    int N;
    cin >> N;

    int sz = 1;
    while(true){
        if(sz * (sz - 1) > 2 * N){
            cout << "No" << endl;
            return 0;
        }
        if(sz * (sz - 1) == 2 * N){
            cout << "Yes" << endl << sz << endl;
            break;
        }
        sz++;
    }

    vector<vector<int>> ans(sz, vector<int>(sz - 1));
    int now = 1;
    rep(i, sz - 1)rep(j, sz - i - 1){
        ans[i][i + j] = now;
        ans[i + j + 1][i] = now;
        now++;
    }

    rep(i, sz){
        cout << sz - 1;
        rep(j, sz - 1)cout << ' ' << ans[i][j];
        cout << endl;
    }
    
}