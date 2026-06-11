#include<bits/stdc++.h>
using namespace std;
int static dp[3002][3002];

int lcs(string str1,string str2,int m,int n)
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str1[i-1] == str2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];

            else 
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]); 
        }

    }

    return dp[m][n];
}

int main()
{
    string s,t;
    cin>>s>>t;
    int m= s.length();
    int n= t.length();

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 ||j==0)
            dp[i][j] = 0;
        }
    }

    lcs(s,t,m,n);

    int i=m,j=n;
    vector <char >vec;
    while(i>0 && j>0)
    {
        if(s[i-1] == t[j-1])
        {
            vec.push_back(s[i-1]);
            i--;
            j--;
        }

        else 
        {
            if(dp[i-1][j] > dp[i][j-1])
                i--;

            else 
                j--;
        }
    }
    reverse(vec.begin(),vec.end());

    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i];
    }
    if(vec.size()==0)
        cout<<" ";

        cout<<"\n";

    return 0;

}