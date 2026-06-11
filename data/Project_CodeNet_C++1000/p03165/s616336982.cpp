#include<bits/stdc++.h>
using namespace std;
void f(string s1,string s2)
{
    if(s1.length()==0 || s2.length()==0)
    return;

    vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));

    
    int i,j;
    for( i=1;i<=s1.length();i++)
    {
        for(j=1;j<=s2.length();j++)
        {
            ///cout<<s2[i-1]<<" - "<<s1[j-1]<<"  ";
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }

            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        //cout<<endl;
    }
    /*for(i=0;i<=s2.length();i++)
    {
        for(j=0;j<=s1.length();j++)
        {
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
    */
    i=i-1;
    j=j-1;
    vector<char> v;
    while(i>0 && j>0)
    {
        //cout<<"("<<i<<" , "<<j<<")"<<endl;
        if(s1[i-1]==s2[j-1])
        {
            //cout<<s2[i-1]<<"  ";
            v.push_back(s1[i-1]);
            i--;
            j--;
            //continue;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            i--;

            else
            j--;
        }
    }
    for(int x=v.size()-1;x>=0;x--)
    {
        cout<<v[x];
    }
    return;
}
int main() {
	string s1,s2;
    cin>>s1>>s2;
    f(s1,s2);
    return 0;
}