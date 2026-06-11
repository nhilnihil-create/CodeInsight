#include <bits/stdc++.h>
using namespace std;


int main()
{   
    string s,t ;
    int n,m;
    cin >> s >> t ;
    n=s.length() ; m=t.length() ;

    int ans[m+1][n+1] ;
    int dp [m+1][n+1];
    
    for (int i=0;i<=m;i++){
        for (int j=0 ;j<=n ;j++)
            dp[i][j]=0 ;
    }

    for (int i=1 ; i<=m ; i++)
        for (int j=1 ; j<=n ;j++){
            if (t[i-1]==s[j-1]){
                ans[i][j]=0 ; // match
                dp[i][j]=dp[i-1][j-1]+1 ;
            }
            else{
                dp[i][j]=dp[i-1][j-1] ;
                ans[i][j]=3 ; // lu
                if (dp[i-1][j]>=dp[i][j]){
                    dp[i][j]=dp[i-1][j] ;
                    ans[i][j]=2 ; // u
                }
                if (dp[i][j-1]>=dp[i][j]) {
                    dp[i][j]=dp[i][j-1] ;
                    ans[i][j]=1 ; // l
                }
            }
        }


    for (int i=0 ; i<= m ;i++)
        ans[i][0]=2 ; // u
    for (int i=0 ; i<= n ;i++)
        ans[0][i]=1 ; // l

    string answer="" ;
    int i=m , j= n ;
    while (i>=0 && j>=0){
        if (ans[i][j]==0) {
            answer+=s[j-1] ;
            i-- ;
            j-- ;
        }
        else if (ans[i][j]==1)
            j-- ;
        else if (ans[i][j]==3){
            i-- ;
            j-- ;
        }
        else
            i-- ;
    }

    reverse(answer.begin(),answer.end()) ;
    cout << answer ;
    return(0);
}

