#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

const int maxn = 3005;

int n;

typedef long long LL;

const int mod = 1e9 + 7;

int dp[maxn][maxn];
char s[maxn];
int pre[maxn][maxn];

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}


int main(){
    cin >> n;
    scanf("%s", s + 1);
    for(int i = 1;i <= n;i++){
        dp[1][i] = 1;
        pre[1][i] = dp[1][i];
        add(pre[1][i], pre[1][i - 1]);
    }
    for(int i = 2;i <= n;i++){
        for(int j = 1;j <= n - i + 1;j++){
            if(s[i - 1] == '<'){
                dp[i][j] = pre[i - 1][j];
            }else{
                dp[i][j] = (pre[i - 1][n] - pre[i - 1][j] + mod) % mod;
            }
        }
        for(int j = 1;j <= n;j++){
            pre[i][j] = dp[i][j];
            add(pre[i][j], pre[i][j - 1]);
        }
    }
    //for(int i = 1;i <= n;i++){
    //    for(int j = 1;j <= n;j++){
    //        cout << i << " " << j << " " << dp[i][j] << endl;
    //    }
    //}
    cout << dp[n][1] << endl;
    return 0;
}
