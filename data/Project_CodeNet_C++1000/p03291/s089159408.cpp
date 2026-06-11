#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;
ll dp[100001][4];
const ll mod = 1000000007;
string s, foo = "ABC";
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    for(int i = s.length(); i >= 0; i--){
        for(int j = 3; j >= 0; j--){
            if(i == s.length()){
                if(j == 3)dp[i][j] = 1;
            }
            else{
                if(s[i] == '?')dp[i][j] += dp[i+1][j]*3;
                else dp[i][j] = dp[i+1][j];
                if(j < 3){
                    if(s[i] == '?' || s[i] == foo[j]){
                        dp[i][j] += dp[i+1][j+1];
                    }
                }
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
