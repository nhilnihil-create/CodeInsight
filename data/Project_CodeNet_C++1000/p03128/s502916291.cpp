#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;

    int s[10]={0,2,5,5,4,5,6,3,7,6};
    int a[m+1];
    for (int i = 1; i <=m ; ++i) {
        cin>>a[i];
    }

    string dp[11000];
    fill_n(dp,11000,"");

    for (int j = 1; j <=m ; ++j) {
        int len1=dp[s[a[j]]].length();
        int len2=dp[0].length();

        if(len1-1==len2)
        {
            dp[s[a[j]]]=max(dp[s[a[j]]],dp[0]+to_string(a[j]));
        }
        else if(len1-1<len2)
        {
            dp[s[a[j]]]=dp[0]+to_string(a[j]);
        }
    }

//    for (int i = 1; i <=20 ; ++i) {
//        cout<<dp[i]<<"\n";
//    }

    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=m ; ++j) {
            int len1=dp[i+s[a[j]]].length();
            int len2=dp[i].length();
            if(len2==0)
                continue;
            if(len1-1==len2)
            {
                dp[i+s[a[j]]]=max(dp[i+s[a[j]]],dp[i]+to_string(a[j]));
            }
            else if(len1-1<len2)
            {
                dp[i+s[a[j]]]=dp[i]+to_string(a[j]);
            }
        }
    }
    cout<<dp[n];
}