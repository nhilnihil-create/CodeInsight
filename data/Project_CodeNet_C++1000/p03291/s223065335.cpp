#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
const int sz=1e5+10,mo=1e9+7;
string s;
int dpA[sz],dpB[sz],dpC[sz],dp[sz];
void solve()
{
    cin>>s;
    const int n=s.size();
    vector<int> dp(4,0);
    dp[0]=1;
    rep(i,n)
    {
        vector<int> ne=dp;
        if(s[i]=='?')
        {
            rep(j,4)
            {
                ne[j]*=3;
                ne[j]%=mo;
            }
        }
        rep(j,3)
        {
            if(s[i]=='A'+j||s[i]=='?')
            {
                ne[j+1]+=dp[j];
                ne[j+1]%=mo;
            }
        }
        dp=move(ne);
    }
    cout<<dp[3]<<endl;

}
main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}