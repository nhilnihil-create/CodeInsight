#include <bits/stdc++.h>
using namespace std;

void LCS(string&s1, string&s2){
    if(s1.size() > s2.size()) s1.swap(s2);
    int m = s1.size();
    int n = s2.size();
    
    int dp[m+1][n+1] = {};
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    

    string s = "";
    
    int i = m, j = n;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            s += s1[i-1];
            i--;j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    
    if(s.size() == 0) s = ' ';
    reverse(s.begin(),s.end());
    cout << s;
}

int main() {
	string s1,s2;
	cin >> s1 >> s2;
	LCS(s1,s2);
	return 0;
}