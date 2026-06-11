// #include <iostream>
// #include <cstdio>
// #include <map>
// #include <set>
// #include <vector>
// #include <algorithm>
// #include <queue>
// #include <stack>
// using namespace std;
// typedef long long ll;
// const int mo=1e9+7;
// #define rep(i, n) for (int i = 0; i < n; i++)
// int u[55];
// ll dp[55];
// char in[2][55];
// vector<int> v;
// void solve()
// {
//     int n,i,j;
//     scanf("%d%s%s",&n,in[0],in[1]);
//     for(i=0;i<n;)
//     {
//         if(i+1==n||in[0][i]==in[1][i])
//         {
//             v.emplace_back(1);
//             i++;
//         }
//         else
//         {
//             v.emplace_back(2);
//             i+=2;
//         }
//     }
//     dp[0]=6;
//     if(v[0]==1)dp[0]=3;
//     for(i=1;i<v.size();i++)
//     {
//         if(v[i]==1&&v[i-1]==1)dp[i]=dp[i-1]*2%mo;
//         if(v[i]==1&&v[i-1]==2)dp[i]=dp[i-1];
//         if(v[i]==2&&v[i-1]==1)dp[i]=dp[i-1]*2%mo;
//         if(v[i]==2&&v[i-1]==2)dp[i]=dp[i-1]*3%mo;
//     }
//     printf("%lld\n",dp[v.size()-1]);
// }
// main()
// {
//     cin.tie(0);
//     ios::sync_with_stdio(0);
//     solve();
//     return 0;
// }

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const int mo = 1e9 + 7;
ll a;
ll b[60];
typedef pair<ll,ll> P ;
vector<P> v;
ll mxps=-mo,mnps=mo,mx=-mo,mn=mo;
void solve()
{
    if(mn>0)rep(i,a-1);
    else if(abs(mx)<abs(mn))
    {
        rep(i,a)if(b[i]>0)v.emplace_back(make_pair(mnps,i));
        for(int i=a-1;i>0;i--)v.emplace_back(make_pair(i,i-1));
        return;
    }
    else 
    {
        rep(i,a)if(b[i]<0)v.emplace_back(make_pair(mxps,i));
    }
    rep(i,a-1)v.emplace_back(make_pair(i,i+1));
}
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>a;
    rep(i,a){
        cin>>b[i];
        if(mx<b[i])
        {
            mxps=i;
            mx=b[i];
        }
        if(mn>b[i])
        {
            mnps=i;
            mn=b[i];
        }
    }
    solve();
    cout<<v.size()<<endl;
    rep(i,v.size())cout<<v[i].first+1<<' '<<v[i].second+1<<endl;
    return 0;
}