#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

const int mod = 1e9+7;

ll dp[100005][5];

void add(ll &a, ll b){
    a += b;
    if(a >= mod) a -= mod;
}

int main(){
    string s; 
    cin >> s;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 0; i < s.size(); i++){
        /*
        for(int j = 0; j < 5; j++){
            //ABCの場所を選ばない場合
            if(s[i] != '?') add(dp[i+1][j], dp[i][j]);
            else add(dp[i+1][j], dp[i][j] * 3 % mod);
        }
        */
        //ABCの場所を選ぶ場合
        if(s[i] == 'A' || s[i] == '?') add(dp[i+1][1], dp[i][0]);
        if(s[i] == 'B' || s[i] == '?') add(dp[i+1][2], dp[i][1]);
        if(s[i] == 'C' || s[i] == '?') add(dp[i+1][3], dp[i][2]);
        
        for(int j = 0; j < 5; j++){
            //ABCの場所を選ばない場合
            if(s[i] != '?') add(dp[i+1][j], dp[i][j]);
            else add(dp[i+1][j], dp[i][j] * 3 % mod);
        }
        
    }
    cout << dp[s.size()][3] << endl;
}