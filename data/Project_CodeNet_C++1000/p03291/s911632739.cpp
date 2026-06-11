#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
const ll mod = 1e9+7;
ll dp[100005][4];
int main(){
    string s; cin >> s;
    int n = s.size();

    for(int i = n; i >= 0; i--){
        for(int j = 3; j >= 0; j--){
            if(i == n) dp[i][j] = (j == 3 ? 1 : 0);
            else{
                dp[i][j] = dp[i+1][j]*(s[i] == '?' ? 3LL : 1LL);
                if(j < 3 && (s[i] == '?' || s[i] == "ABC"[j])) dp[i][j] += dp[i+1][j+1];
                dp[i][j] %= mod;
            }
        }
    }

    ll ans = dp[0][0];
    cout << ans << endl;
}