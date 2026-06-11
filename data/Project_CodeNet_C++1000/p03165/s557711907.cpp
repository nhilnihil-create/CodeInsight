#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fastio  ios::sync_with_stdio(false); cin.tie(0);

struct BeingZero{
    void lcsCalculate(string s1, string s2, vector< vector<int> > &dp){
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                if (s1[i-1] == s2[j-1]) 
                    dp[i][j] = dp[i-1][j-1] + 1;
                dp[i][j] = max(dp[i][j], max(dp[i][j-1], dp[i-1][j]));
            }
        }
    }

    string getLCS(string s1, string s2, vector< vector<int> > &dp){
        string s = "";
        int i = s1.size();
        int j = s2.size();
        while (i > 0 && j > 0){
            if (dp[i-1][j-1] + 1 == dp[i][j] && dp[i-1][j] + 1 == dp[i][j] && dp[i][j-1] + 1 == dp[i][j]){
                i--; 
                j--; 
                s = s1[i] + s; //As we are travelling backward reverse the string
            }
            else if (dp[i][j-1] > dp[i-1][j]) 
                j--;
            else
                i--;
        }
        return s;
    }
};


int main() {
    fastio;
    BeingZero bz;
    string s1, s2;
    while(cin>>s1>>s2){
        int n1=s1.size();
        int n2=s2.size();
        vector< vector<int> > dp(n1+1, vector<int>(n2+1, 0));
        bz.lcsCalculate(s1, s2, dp);
        //cout<<dp[n1][n2]<<"\n";
        cout<<bz.getLCS(s1, s2, dp)<<"\n";
    }
    return 0;
}

