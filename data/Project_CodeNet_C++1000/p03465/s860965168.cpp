#include <bits/stdc++.h>
#define int         long long
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define mi          map<int,int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define endl        '\n'
#define hell        1000000007
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int> d(200005);
    bitset<4000007> dp;
    
    int sum=0;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
        sum+=d[i];
        dp |=dp <<d[i];
    }
    int odd=sum%2;
    for(int i=sum/2 +odd;i<4000007;i++)
    {
        if(dp[i])
        {
            cout<<i;
            return;
        }
    }
}
signed main(){
    io;
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}