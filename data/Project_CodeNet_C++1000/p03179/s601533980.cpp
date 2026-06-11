# include <bits/stdc++.h>
using namespace std;
const int N = 3005, mod = 1e9 + 7;
int n, ans, dp[N][N], sum[N];
string s;
int add(int a, int b){
    if((a += b) >= mod)a -= mod; 
    return a;
}
int f(int l, int r){
    return add(sum[r], mod - sum[l - 1]);
}
int main(){
    cin >> n >> s;s = '#' + s;
    dp[1][1] = 1; sum[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(s[i - 1] == '<'){
                dp[i][j] = add(dp[i][j], f(1, j - 1));
            }else{
                dp[i][j] = add(dp[i][j], f(j, i - 1)); 
            }
        }
        sum[0] = 0;
        for(int j = 1; j <= i; j++){
            sum[j] = add(sum[j - 1], dp[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        ans = add(ans, dp[n][i]);
    }
    cout << ans << endl;
}