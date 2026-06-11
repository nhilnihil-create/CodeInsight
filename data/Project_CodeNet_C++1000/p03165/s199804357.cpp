#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<vector<int>>dp(n, vector<int>(m));

    dp[n-1][m-1] = (s[n-1] == t[m-1]);

    for(int i = n-2; i >= 0; i--){
        dp[i][m-1] = (s[i] == t[m-1]) | dp[i+1][m-1];
    }

    for(int i = m-2; i >= 0; i--){
        dp[n-1][i] = (s[n-1] == t[i]) | dp[n-1][i+1];
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = m-2; j >= 0; j--){
            if(s[i] == t[j]){
                dp[i][j] = 1+dp[i+1][j+1];
            }else{
                dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }

    string out;
    int i = 0, j = 0;
    while(true){
        if(i == n-1){
            if(dp[i][j] == 1){
                out+=s[i];
            }
            break;
        }else if(j == m-1){
            if(dp[i][j] == 1){
                out+=t[j];
            }
            break;
        }else if(s[i] == t[j]){
            out += s[i];
            i++; j++;
        }else if(dp[i+1][j] > dp[i][j+1]){
            i++;
        }else{
            j++;
        }
    }
    cout<<out<<endl;
}
