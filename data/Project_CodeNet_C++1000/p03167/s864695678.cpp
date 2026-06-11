#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;
const int N = 1007;
const int inf = 1e9 + 7;
bool a[N][N];
int dp[N][N];
int w, h;

int dio(){
    dp[h - 1][w - 1] = 1;
    for (int i = h - 1; i >= 0; i--){
        for (int j = w - 1; j >= 0; j--){
            if (!a[i][j]){
                dp[i][j] = 0;
            }else{
                if ((i != h - 1) || (j != w - 1)){
                    dp[i][j] = ((dp[i + 1][j] % inf) + (dp[i][j + 1] % inf)) % inf;
                }
            }
        }
    }
    return dp[0][0];
}

int main(){
    ///preprocessing
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    fio;
    ///code below
    cin >> h >> w;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            char t;
            cin >> t;
            if (t == '.'){
                a[i][j] = true;
            }else{
                a[i][j] = false;
            }
        }
    }
    cout << dio();
}
