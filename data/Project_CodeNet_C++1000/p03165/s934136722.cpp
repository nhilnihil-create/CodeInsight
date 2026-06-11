#include<bits/stdc++.h>
using namespace std;

void boost1() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    boost1();
    string s,t;
    cin>>s;
    cin>>t;
    int i,j,n1=s.length(),n2=t.length();
    int dp[3001][3001];
    memset(dp,0,sizeof(dp));
    int mx=0;
    for(i=0;i<=n1;i++)
    {
        for(j=0;j<=n2;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(s[i-1]==t[j-1])
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            }
            mx=max(mx,dp[i][j]);
        }
    }  
    // cout<<mx<<endl;
    string lcs="";
    i = n1;
    j = n2; 
   while (i > 0 && j > 0) 
   { 
      if (s[i-1] == t[j-1]) 
      { 
        //   lcs[index-1] = X[i-1];
          lcs+=s[i-1];
          i--; j--;
        //   index--;
      } 
      else if (dp[i-1][j] > dp[i][j-1]) 
         i--; 
      else
         j--; 
   }  
   reverse(lcs.begin(),lcs.end());
   cout<<lcs<<endl; 
}