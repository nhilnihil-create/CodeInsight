#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define hell 1000000007
#define PI 3.14159265358979323846
#include <fstream>
using namespace std;

int main()
{
    //  freopen("timber_input.txt", "r", stdin);
   // freopen("out3_test.txt", "w", stdout);
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
   // cin>>t;
    while(t--) {
    ll n1,n2,i,j,w;
    string s,t;
    cin>>s>>t;
    n1=s.length();
    n2=t.length();
    ll dp[n1+5][n2+5];
    for(i=0;i<=n1;i++)
        dp[i][0]=0;
    for(i=0;i<=n2;i++)
        dp[0][i]=0;
    for(i=1;i<=n1;i++)
        for(j=1;j<=n2;j++)
    {
        if(s[i-1]==t[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    stack<char> st;
    i=n1;
    j=n2;
    while(i>0 && j>0)
    {
        if(s[i-1]==t[j-1])
        {
            st.push(s[i-1]);
            --i;
            --j;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                --i;
            else
                --j;
        }
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    }

}
