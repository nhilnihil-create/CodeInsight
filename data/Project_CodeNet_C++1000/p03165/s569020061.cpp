#include<bits/stdc++.h>
#define ll long long
using namespace std;

main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);cin.tie(NULL);

    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    int dp[n][m];
    fill(dp[0],dp[n-1]+m,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i)   dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(j)   dp[i][j]=max(dp[i][j],dp[i][j-1]);
            // dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(s[i]==t[j])
                dp[i][j]=max(dp[i][j],((i>0&&j>0)?dp[i-1][j-1]:0)+1);
        }
    }
    int i=n-1,j=m-1;
    int len=dp[n-1][m-1];
    string res;
    while(len && i>=0 && j>=0){
        if(i && dp[i-1][j]==dp[i][j]){
            i--;
            continue;
        }

        if(j && dp[i][j-1]==dp[i][j]){
            j--;
            continue;
        }

        res+=s[i];
        len--;
        i--;j--;
    }
    reverse(res.begin(),res.end());
    cout<<res<<"\n";
}