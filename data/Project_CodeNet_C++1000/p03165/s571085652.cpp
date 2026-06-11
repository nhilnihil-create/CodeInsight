/*
    Author  :   jignesh1604
    College :   SVNIT
*/

#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s , d;
    cin >> s >> d;
    long long int n = s.size() , m = d.size() , i , j;
    vector<vector<long long int>> dp(n+1 , vector<long long int> (m+1 , 0));
    for(i = 1 ; i <= n ; i++) {
        for(j = 1 ; j <= m ; j++) {
            if(s[i-1] == d[j-1]) {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    i = n;
    j = m;
    string fin = "";
    while(i > 0 && j > 0) {
        if(s[i-1] == d[j-1]) {
            fin += s[i-1];
            i--;
            j--;
        }
        else {
            if(dp[i-1][j] > dp[i][j-1]) {
                i--;
            }
            else {
                j--;
            }
        }
    }
    reverse(fin.begin() , fin.end());
    cout << fin << "\n";
}

int main() {
    long long int tc = 1;
    // cin >> tc;
    while(tc-- > 0) {
        solve();
    }
}