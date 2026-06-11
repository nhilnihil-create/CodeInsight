#include <bits/stdc++.h>
#define ll int
using namespace std;
void LCS(string &text1, string &text2, string &res) {
    int l1 = (ll)text1.size();
    int l2 = (ll)text2.size();
    int dp[l1+2][l2+2];
    for(int i=0; i<=l1; i++)
        dp[i][0] = 0;
    for(int j=0; j<=l2; j++)
        dp[0][j] = 0;
    for(int i=1; i<=l1; i++)
    {
        for(int j=1; j<=l2; j++)
        {
            if(text1[i-1] == text2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    ll i=l1, j=l2;
    while(i>=1 && j>=1)
    {
        if(text1[i-1] == text2[j-1])
        {
            res+= text1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    reverse(res.begin(), res.end());
}
string longestCommonSubsequence(string &a, string &b) {
    string res = "";
    LCS(a, b, res);
    return res;
}

int main()
{
	string a, b;
	cin>>a>>b;
	cout<<longestCommonSubsequence(a, b);
	return 0;
}