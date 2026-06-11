#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    string s, t, r;
    cin >> s >> t;
    int sizs = s.size(), sizt = t.size();
    int dp[sizs+1][sizt+1];

    for(int i = 0; i <= sizs; i++)  dp[i][0] = 0;
    for(int i = 0; i <= sizt; i++)  dp[0][i] = 0;

    for(int i = 1; i <= sizs; i++){
        for(int j = 1; j <= sizt; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = (1 + dp[i-1][j-1]);
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int ind = sizs;
    for(int i = sizt; i >= 1 && ind > 0;){
//        cout << ind << " " << i << '\n';
        if(dp[ind][i] == dp[ind-1][i]){
            ind--;
        } else if(dp[ind][i] == dp[ind][i-1]) {
            i--;
        } else {
            r += s[ind-1];
            ind--;  i--;
        }
    }
    reverse(r.begin(), r.end());
    cout << r;
}