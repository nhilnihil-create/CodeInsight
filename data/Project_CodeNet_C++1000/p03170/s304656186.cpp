#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
   int n,k;
   cin>>n>>k;
   int a[n];
   for(int i=0;i<n;i++)
        cin>>a[i];
    vector<bool> dp(k+1,false);
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=a[j]&&dp[i-a[j]]==false)
                dp[i]=true;
        }
    }
    string s="";
    s=dp[k]==true?"First":"Second";
    cout<<s<<endl;
    return 0;
}