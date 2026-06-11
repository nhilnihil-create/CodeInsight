#include<bits/stdc++.h>
using namespace std;
int n;
string s;
string t;
int dp[20][20];
int get(string x,string y)
{
    memset(dp , 0 , sizeof(dp));
    //cout<<x<<' '<<y<<' '<<t<<endl;
    dp[0][0] = 1;
    for(int i = 0;i <= x.size();i++){
        for(int j = 0;j <= y.size();j++){
            if(i == 0 && j == 0) continue;
            if(i > 0 && x[i - 1] == t[i + j - 1]) dp[i][j] += dp[i - 1][j];
            if(j > 0 && y[j - 1] == t[i + j - 1]) dp[i][j] += dp[i][j - 1];
            //printf("%d ",dp[i][j]);
        }
        //cout<<endl;
    }
    return dp[x.size()][y.size()];
}
int main()
{
    scanf("%d",&n);cin>>s;
    for(int i = n;i < s.size();i++) t += s[i];
    reverse(t.begin() , t.end());
    long long ans = 0;
    for(int i = 0;i < (1<<n);i++){
        string x , y;
        for(int j = 0;j < n;j++){
            if((i>>j) & 1) x += s[j];
            else y += s[j];
        }
        ans += get(x , y);
    }
    cout<<ans<<endl;
    return 0;
}
