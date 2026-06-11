//見　た　な
//見たな
//見　た　な

#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

const ll MOD = 1000000007;
ll dp[100001][4]; //i+1文字目まで考えた時に、j文字目まで選んだ場合の個数

//i文字目まで見た上で何通りあるかを考えると、上手く行かない
//dpの状態数を増やそう！
//いやそれは分かるけどなんでこの発想が出てくるんですか？
//s[i]を選ぶ文字に含めるかどうかで二分が出来るから、そこで分岐はわかる


int main(){
    string s; cin >> s;
    dp[0][0] = 1;
    rep(i,s.size()){
        rep(j,4){ //S[i]を選ばない場合、
            if(s[i] != '?') dp[i+1][j] += dp[i][j];
            else dp[i+1][j] += 3*dp[i][j] % MOD;
            dp[i+1][j] %= MOD;
        }
        if(s[i] == 'A' || s[i] == '?') dp[i+1][1] = (dp[i+1][1] + dp[i][0]) % MOD;
        if(s[i] == 'B' || s[i] == '?') dp[i+1][2] = (dp[i+1][2] + dp[i][1]) % MOD;
        if(s[i] == 'C' || s[i] == '?') dp[i+1][3] = (dp[i+1][3] + dp[i][2]) % MOD;
    }
    cout << dp[s.size()][3] << endl;
}