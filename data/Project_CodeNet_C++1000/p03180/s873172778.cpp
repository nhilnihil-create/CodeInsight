#include<bits/stdc++.h>
using namespace std;
#define Elhabashy ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void input()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
}
const int N=18,mod=1e9+7;
typedef long long ll;
ll n,arr[N][N],dp[1<<N],cm[1<<N];
ll solve(int msk = (1<<n)-1)
{
    if (!msk)
        return 0;
    ll &ret = dp[msk];
    if (~ret)
        return ret;
    ret = -1e9;
    for(int cur=msk;cur;cur=((cur-1)&msk)){
        int tmp=cur^msk;
        ret=max(ret,cm[cur]+solve(tmp));
    }
    return ret;
}
void gen1()
{
    for(int i=0; i<(1<<n); i++)
    {
        ll sum=0;
        vector<int>tmp;
        for(int j=0; j<n; j++)
        {
            if((1<<j)&i)
            {
                tmp.push_back(j);
            }
        }
        for(int x=0; x<tmp.size(); x++)
        {
            for(int y=x+1; y<tmp.size(); y++)
            {
                int idx1=tmp[x],idx2=tmp[y];
                sum+=arr[idx1][idx2];
            }

        }
        cm[i]=sum;

    }
}
int main()
{
    Elhabashy
    input();
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cin>>arr[i][j];
    }
    gen1();
    memset(dp,-1,sizeof dp);
    cout<<solve()<<endl;
}
