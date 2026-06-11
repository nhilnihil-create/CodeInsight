#include<bits/stdc++.h>
using namespace std;
// problem F

void lcs(string s, string ss, int n , int m){
    int dp[n+1][m+1];

    for(int i = 0; i<n+1; i++)
        dp[i][0] = 0;
    for(int i = 1 ; i<m+1; i++)
        dp[0][i] = 0;


    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++){
            if(s[i-1] == ss[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

    int index = dp[n][m];

    char arr[index + 1];
    arr[index] = '\0';
    

    int i = n, j = m;

    while(i > 0 && j > 0)
    {
        if(s[i-1] == ss[j-1])
        {
            arr[index - 1] = s[i - 1];
            i--;
            j--;
            index--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    
    cout<<arr<<endl;


}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    string s1, s2;
    cin>>s1 >> s2;

    int len1 = s1.length();
    int len2 = s2.length();

    lcs(s1, s2, len1, len2);
    

    return 0;
}
