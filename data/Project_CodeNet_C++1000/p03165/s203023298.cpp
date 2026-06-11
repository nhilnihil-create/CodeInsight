#include<bits/stdc++.h>
using namespace std;
//#define int long long

//ask the right questions.  

// dp[i][j] means maximum subsequence length when we have seen upto ith index in s and jth index in t.    

int dp[3001][3001];
int choices[3001][3001];

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();

    //trivial case;

    //iteratin gover items (not indexes in dp equation)
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //not equal: cannot include
            if(s[i-1]!=t[j-1]){
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                if(dp[i-1][j]>=dp[i][j-1])
                    choices[i][j]=1;
                else
                    choices[i][j]=2;
            }
            else{//equal: choice is to include or not
                //not-include to initialize dp[i][j]
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                if(dp[i-1][j]>=dp[i][j-1])
                    choices[i][j]=1;
                else
                    choices[i][j]=2;
                //now see whetther inclusion maximises over non inclusion
                dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);
                if(dp[i][j]<=dp[i-1][j-1]+1)
                    choices[i][j]=3;
            }
        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout << choices[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //cout << dp[n][m] <<endl;
    int i = n; int j = m;
    string ans="";
    while(i>0 && j>0)
    {
        if(choices[i][j]==1)
        {
            //cout << "choice 1" <<endl;
            //cout << i << " " <<j <<endl;
            i--;
        }
        else if (choices[i][j]==2)
        {
            //cout << "choice 2" <<endl;
            //cout << i << " " <<j <<endl;
            j--;
        }
        else
        {
            ans+=s[i-1];
            i--;
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans <<endl;

    return 0;
}

