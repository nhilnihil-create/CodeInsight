#include <iostream>
#include<bits/stdc++.h>

#define ll long long
using namespace std;


void lcs(string a ,string b)
{

    int n = a.length();
    int m = b.length();
     

    int max_len = 0;
    

    vector<vector<int>>dp(n + 1 ,vector<int>(m+1 ,0));
    for(int i = 0 ;i <= n ; i++)
    {
        for(int j = 0 ; j<= m ;j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            
            if(a[i-1] == b[j-1])
            {
                dp[i][j] = 1+ dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }

            if(dp[i][j] > max_len)
            max_len = dp[i][j];
        }

    }

    //cout<<max_len<<endl;
    
    string s;
   int i = n, j =m;
    while(i > 0 && j > 0)
    {
        if(a[i-1] == b[j-1])
        {
            s = s + a[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(s.begin() , s.end());
    cout<<s<<endl;
}
int main()
{
    string s,t;

    cin>>s>>t;

     lcs(s,t);
}