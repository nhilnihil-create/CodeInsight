#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdlib>
#include<set>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

#include<iostream>

int main(){
    int const INF = 1000000000;
    int n, c;
    cin >> n >> c;
    int d[c][c];
    int col[n][n];
    rep(i, c)rep(j, c) cin >> d[i][j];
    rep(i, n)rep(j, n) {
        cin >> col[i][j];
        col[i][j]--;
    }
    int a[3][c];
    rep(i, 3)rep(j, c) a[i][j] = 0;
    rep(i, n)rep(j, n){
        int pos = (i + 1 + j + 1) % 3;
        a[pos][col[i][j]]++;
    }
    // rep(i, 3){
    //     rep(j, c){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = INF;
    rep(i, c)rep(j, c)rep(k, c){
        if (i != j && j != k && k != i){
            int ans1 = 0;
            rep(l, c){
                ans1 += a[0][l] * d[l][i];
                ans1 += a[1][l] * d[l][j];
                ans1 += a[2][l] * d[l][k];
            }
            ans = min(ans1, ans);
        }
        
    }
    cout << ans << endl;
}