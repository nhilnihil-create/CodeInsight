#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 7;
const int mod = 1e9 + 7;

int n;
int m;
int d[N][N];
char c[N][N];
int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> c[i][j];
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(i == 1 && j == 1){
                d[i][j] = 1;
            }else{
                if(c[i][j] == '.'){
                    d[i][j] = ((d[i][j] + d[i - 1][j]) % mod + d[i][j - 1]) % mod;
                }
            }
        }
    }
    cout << d[n][m] << "\n";
}

